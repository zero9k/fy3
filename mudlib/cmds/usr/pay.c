
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int money;
	object ob,obj;
	if(! arg)
		return notify_fail("pay somebody\n");

	if(! ob=present(arg,environment(me)))
		return notify_fail("这儿没有这么个人。\n");
	if(! ob->is_character())
		return notify_fail("看清，它并不是生物。\n");
	if(! living(ob))
		return notify_fail("你得先把他弄醒再说。\n");
	if(! (money=ob->query("money_need")))
		return notify_fail("看样子"+
		ob->query("name")+"并不想接受你的钱财。\n");
	if( (string)ob->query("banghui")&&
		me->query("banghui")==ob->query("banghui"))
		return notify_fail(ob->query("name")+"呵呵笑道：自己帮中兄弟，何必如此客气？\n");
	if(! me->can_afford(money))
		return notify_fail(ob->query("name")+"哼了一声道：等你身上带够了钱再来吧。\n");
	if(! me->pay_money(money))
		return notify_fail(ob->query("name")+"哼了一声道：等你身上带够了钱再来吧。\n");
	message_vision("$N恭恭敬敬的从腰包中掏出"+
		chinese_number(money/100)+"两银子交给$n。\n",me,ob);
	message_vision("$N点了点头道："+me->query("name")+"，你可以过去了。\n",
		ob);
	me->set_temp("oldsix/can_leave",1);
	"/cmds/adm/ctom"->save_money(ob,money);
	return 1;
	

}

int help()
{
	write(@TEXT
指令格式：pay <somebody>

这条指令是用来付钱给某NPC的，由于一些NPC控制着
一些地盘，你要想通过的话，除非你和他是同帮兄弟
或是你确信自己可以打败他，否则你还是乖乖的付些
银两给他吧。
TEXT
	);
	return 1;
}
