// Mr. musix yangzhou 姚老板

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("姚老板", ({ "yaolaoban","yao","laoban" }) );
	set("title", "姚记钱庄");
	set("gender", "男性" );
	set("age", 46);
  
	set("str", 22);
	set("cor", 30);
	set("cps", 30);
	set("int", 26);
	set("per", 23);
	set("con", 24);
	set("spi", 30);
	set("kar", 25);

	set("long","老与事故的钱庄老板。\n");
 
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("pursuer", 1);
	set("env/wimpy", 70);

	set("max_atman", 1000);		set("atman", 1000);		set("atman_factor", 3);
	set("max_force", 1000);		set("force", 1000);		set("force_factor", 3);
	set("max_mana", 1000);		set("mana", 1000);		set("mana_factor", 3);

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
        set("inquiry", ([
            "利息":   "我们庄的规矩是提取两成保管费。\n",
            "lixi":   "我们庄的规矩是提取两成保管费。\n",
                       ]) );


	setup();
	
	carry_object(__DIR__"obj/duanjian")->wield();
	carry_object(__DIR__"obj/hupi")->wear();

	add_money("gold", 5);
}

int accept_fight(object me)
{
	kill_ob(me);
	return 1;
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "wen");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
        add_action("do_convert", "huan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	delete_temp("busy");
}

void enough_rest()
{
	delete_temp("busy");
}

int do_check()
{
	// here we use 3 units to display bank infos
	int total = (int)this_player()->query("balance");
        
	
	if (!total || total < 0) {
		this_player()->set("balance", 0);
		return notify_fail("您在敝商号没有存钱。\n");
	}
	write("你核对了帐本，在庄里共存有" + 
		MONEY_D->money_str(total) + "\n");
        if (total > 2000000) {
                this_player()->set("balance",0);
                write("姚老板奸笑道：这么多钱，来路不正吧？\n");
                write("姚老板一拍桌子道：这钱改姓姚了！\n");
                write("说完一脚把你踢出去了.\n");
                this_player()->move("/d/yangzhou/dongguan1");
        }
	return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
	object me;
	
	if (query_temp("busy"))
		return notify_fail("这就去拿帐本，请稍候。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
	{
		return notify_fail("命令格式：huan <数量> <货币> to <新货币单位>\n");
	}

	from_ob = present(from + "_money", me);
	to_ob = present(to + "_money", me);

	if (!to_ob && file_size("/obj/money/" + to + ".c") < 0)
	{
		return notify_fail("你想换成什么？\n");
	}
	if (!from_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想白赚啊？\n");
	}
	if ((int)from_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + from_ob->query("name") + "不够。\n");
	}
	
	bv1 = from_ob->query("base_value");
	if (!bv1)
	{
		return notify_fail("这样东西不值钱。\n");
	}

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, 
"query", "base_value" );
	
	if (bv1 < bv2)
		amount -= amount % (bv2 / bv1);	

	if (amount == 0)
	{
		return notify_fail("这些" + from_ob->query("name") + "不够换。\n");
	}

	// allowed to convert now
	set_temp("busy", 1);	

	from_ob->add_amount(-amount);

	if (!to_ob) {
		to_ob = new("/obj/money/" + to);
		to_ob->set_amount(amount * bv1 / bv2);
		to_ob->move(me);
	}
	else
		to_ob->add_amount(amount * bv1 / bv2);
	
	message_vision(sprintf("$N从身上取出%s%s%s，换成了%s%s%s。\n",
	chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
	chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
	to_ob->query("name")), me);

//	from_ob->add_amount(-amount);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);

	return 1;
}

int do_deposit(string arg)
{
	string what;
	int amount;
	object what_ob, me;

	if (query_temp("busy"))
		return notify_fail("您请坐，这就去取帐本。\n");

	me = this_player();

	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式: cun <数量> <货币>\n");
	}

	what_ob = present(what + "_money", me);
	if (!what_ob)
	{
		return notify_fail("你身上没有带这种钱。\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想存多少" + what_ob->query("name") + "？\n");
	}
	if ((int)what_ob->query_amount() < amount)
	{
		return notify_fail("你带的" + what_ob->query("name") + "不够。\n");
	}

	// deposit it
	set_temp("busy", 1);	

	me->add("balance", what_ob->query("base_value") * amount);
	what_ob->add_amount(-amount);
	message_vision(sprintf("$N拿出%s%s%s，存进了钱庄。\n", 
	chinese_number(amount), what_ob->query("base_unit"), 
	what_ob->query("name")), me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}

int do_withdraw(string arg)
{
	int amount, v;
	string what;
	object me;

	if (query_temp("busy"))
		return notify_fail("您请稍候.....。\n");

	me = this_player();
	
	if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
	{
		return notify_fail("命令格式：qu <数量> <货币单位>\n");
	}
	if (amount < 1)
	{
		return notify_fail("你想取出多少钱？\n");
	}
	if (file_size("/obj/money/" + what + ".c") < 0)
	{
		return notify_fail("你想取出什么钱？\n");
	}
	what = "/obj/money/" + what;
        if (amount > 2000000) 
           {
                return notify_fail("你想消遣本大爷？滚！\n");
           }        

	if ((v = amount * what->query("base_value")) > me->query("balance"))
	{
		return notify_fail("你存的钱不够。\n");
	}

	set_temp("busy", 1);	

	me->add("balance",  -v);
	MONEY_D->pay_player(me, v = v * 8 / 10);
	
	message_vision(sprintf("$N从钱庄里取出%s。\n", MONEY_D->money_str(v)),
		me);

	remove_call_out("enough_rest");
	call_out("enough_rest", 5);
	return 1;
}
