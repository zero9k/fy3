// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands

#include <dbase.h>

string is_vendor_good(string arg)
{
	string *goods;
	object ob;
	int i;

	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			if (goods[i]->id(arg))
				return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要估什么的价？\n");
	
	if (ob->query("money_id"))
		return notify_fail("你没用过钱啊？\n");

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "一文不值！\n");
	else 
		write(ob->query("name") + "值" + 
		MONEY_D->price_str(value * 70 / 100) + "。\n");
	return 1;
}

int do_sell(string arg)
{
	object ob,room,*inv;
	int value,i;
	
	if( this_player()->is_busy())
		return notify_fail("你正忙着呢！\n");

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要卖什么？\n");

	if (ob->query("money_id"))
		return notify_fail("你想卖「钱」？？\n");

	if (stringp(ob->query("no_drop")))
		return notify_fail("这样东西不能卖。\n");
	if ( (int)ob->query("no_sell"))
		return notify_fail("这样东西不能卖。\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("卖给你好不好？\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	
        if (ob->query("shaolin"))
                return notify_fail("小的只有一个脑袋，可不敢买少林庙产。\n");
	
	value = ob->query("value");
	if (value>20000) return notify_fail("太贵了，我买不起啊。\n");
	room=find_object("/obj/dangroom");
	if( !objectp(room))	room=load_object("/obj/dangroom");

	if (value < 30)
		write(ob->query("name") + "一文不值！\n");
	else if((int)ob->query("oldsix/damage"))
		write("先把"+ob->query("name")+"拿去修修吧。\n");
	else {
		this_player()->start_busy(2);
		inv=all_inventory(room);
		for(i=0;i<sizeof(inv);i++)		{
			if( base_name(inv[i])!=base_name(ob))	continue;
			inv[i]->add("oldsix/mount",1);
			ob->set("be_dest",1);
			break;
		}
		if( !ob->query("be_dest"))	{
			if( !ob->move(room))
				return notify_fail("对不起，本店货仓装不下了。\n");
			ob->set("oldsix/mount",1);
		}

		message_vision("$N卖掉了一" + ob->query("unit") + 
		ob->query("name") + "给$n。\n", this_player(), this_object());
		MONEY_D->pay_player(this_player(), value * 50 / 100);
//		if (value < 50)
//			destruct(ob);
		if( ob->query("be_dest"))
			destruct(ob);
	}
	return 1;
}

int do_list()
{
	string *goods;
	object *inv,room;
	int i;

	room=find_object("/obj/dangroom");
	if( !objectp(room))	room=load_object("/obj/dangroom");

	inv = all_inventory(room);

	if (!sizeof(inv))
		return notify_fail("目前没有可以卖的东西。\n");
	
	printf("你可以向%s购买下列物品：\n", query("name"));
	for (i = 0; i < sizeof(inv); i++) 
		if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
		printf("%30-s：%30-s：%10s\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
		inv[i]->query("oldsix/mount")+inv[i]->query("unit"));
	return 1;
}	

int do_buy(string arg)
{
	int value, val_factor;
	string ob_file;
	object ob,room;
	
	if( this_player()->is_busy())
		return notify_fail("你正忙着呢！\n");
	room=find_object("/obj/dangroom");
	if( !objectp(room))	room=load_object("/obj/dangroom");

	if (!arg)
		return notify_fail("你想买什么？ 1\n");
	else if (!(ob = present(arg, room)))
			return notify_fail("你想买什么？ 2\n");

	val_factor = 12;

	this_player()->start_busy(2);
	
	switch (MONEY_D->player_pay(this_player(), ob->query("value") *  val_factor / 10)) {
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
		message_vision("$N从$n那里买下了一" + ob->query("unit") + 
		ob->query("name") + "。\n", this_player(), this_object());
		if( ob->query("oldsix/mount")<=1)	
			ob->delete("oldsix/mount");
		else	{
			ob->add("oldsix/mount",-1);
			ob=new(base_name(ob));
		}
		ob->move(this_player());
	}

	return 1;
}

void enough_rest()
{
        delete_temp("busy");
}


