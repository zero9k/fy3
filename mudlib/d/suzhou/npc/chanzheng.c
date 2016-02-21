// guard.c

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("单正",({"chan zheng","chan"}));
	set("title","铁面判官");
	set("gender", "男性" );
	set("age",24);
	set("str",50);
	set("cor", 30);
	set("cps", 30);
	set("int",30);
	set("con",50);
	set("long",
	"满面红光，童颜鹤发，神情甚是谦和。\n"
	);
	set("combat_exp",50000);
	set("attitude","friendly");
	setup();
	carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	ob=this_player();
	if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
}
int greeting(object ob)
{
	int t1,t2,lt,m,s;
	string time;
	time="";
	if(ob->query("oldsix_flag/lao")==0)	{
		message_vision(CYN"单正对着$N说道：你可以出去了，别在这儿瞎转悠！\n"NOR,ob);
		return 1;
	}
	t1=ob->query("mud_age")-ob->query("oldsix_flag/time");
	switch(ob->query("oldsix_flag/long"))	{
		case 1 :	t2=20*60;
				break;
		case 2 :	t2=10*60;
				break;
		case 3 :	t2=5*60;
				break;
				}
	lt=t2-t1;
	if (lt<=0) {
	tell_object(ob,CYN"单正悄悄的告诉你：马上就可以出去啦！\n"NOR);
		return 1;
			}
	s=lt%60;
	lt=lt/60;
	m=lt;
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	tell_object(ob,CYN"单正悄悄告诉你：还要等"+time+"左右才能出狱。\n"NOR);
	return 1;
}
