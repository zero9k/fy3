// jindan.c 九转金丹
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("九转金丹", ({ "jindan","dan" }) );
	set("long", "一颗金光闪闪异香扑鼻的大丸子，相传为太上老君所制，灵效无比。\n");
	set("unit", "颗");
	set("weight", 50);
	set("value", 1000);
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object ob;
	if( !id(arg) ) return notify_fail("你要吃什麽？\n");

	ob=this_player();
	ob->set("kee",(int)ob->query("max_kee"));
	ob->set("gin",(int)ob->query("max_gin"));
	ob->set("sen",(int)ob->query("max_sen"));
	ob->set("eff_kee",(int)ob->query("max_kee"));
	ob->set("eff_gin",(int)ob->query("max_gin"));
	ob->set("eff_sen",(int)ob->query("max_sen"));

	ob->set("atman", (int)ob->query("max_atman"));
	ob->set("force", (int)ob->query("max_force"));
	ob->set("mana", (int)ob->query("max_mana"));

	ob->set("food",((int)ob->query("str")-10)*10+200);
	ob->set("water",((int)ob->query("str")-10)*10+200);

	write( HIY "你服下一颗九转金丹，立刻变得精力充沛，红光满面！\n" NOR);

	message("vision", HIY + ob->name() + "服下一颗九转金丹，立刻变得精力充沛，红光满面！" NOR,
		environment(ob), ob);
	destruct(this_object());
	return 1;
}
