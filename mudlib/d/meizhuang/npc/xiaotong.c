// woodcutter.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("小童",({"xiao tong","tong","kid"}));
	set("gender", "男性" );
	set("age",10);
	set("long","眉清目秀的小男孩。\n");
	set("combat_exp",500);
	setup();
	carry_object("/obj/cloth")->wear();
}
void init()
{
	::init();
	add_action("do_sleep","sleep");
}
int do_sleep()
{
	object me;
	me=this_player();
	if(me->query("family/family_name")!="孤山梅庄")	{
	command("say 这儿暂不接待其他门派弟子。\n");
	return 1;
	}
	if(me->query_temp("sleeped"))	{
	command("say 不是刚睡过吗？\n");
		return 1;
	}
	return 0;
}
