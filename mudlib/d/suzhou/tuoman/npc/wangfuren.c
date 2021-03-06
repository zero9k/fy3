// guard.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("王夫人",({"wang furen","wang","furen"}));
	set("title","曼陀山庄庄主");
	set("gender","女性");
	set("age",35);
	set("str",40);
	set("cor", 30);
	set("mingwang",-1);
	set("cps", 30);
	set("int",30);
	set("con",40);
	set("per",30);
	set("long",
		"身穿鹅黄绸衫，脸上颇有风霜岁月的痕迹。\n"
	);
	set("combat_exp",100000);
	set("attitude","friendly");
	set_skill("parry",60);
	set_skill("dodge",60);
	set_skill("blade",70);
	set_temp("apply/dodge",60);
	set_temp("apply/parry",60);
	set_temp("apply/attack",60);
	setup();
	carry_object(__DIR__"obj/dress")->wear();
	carry_object("obj/weapon/blade")->wield();
}
void init()
{
	object ob;
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	int count;
	        mapping my;
	if( !ob || environment(ob) != environment() ) return;
	my=ob->query_entire_dbase();
	if (this_object()->is_killing(my["id"])) {
//	message_vision(RED"王夫人喝道："+ob->query("name")+"！哪里走！\n"NOR,ob);
	return ;
	}
	if(ob->query("gender")=="女性")	{
	message_vision(CYN"王夫人温和的对$N说道：武功上有什么疑难，可以去问问语嫣。\n"NOR,ob);
		return;
	}
	count=ob->query("oldsix_flag/wangfuren");
	if(!count||count==0)	{
		message_vision(CYN"王夫人眉头微皱，对$N说道：我最讨厌臭男人在我房间里转窜，下次别让我再见到你。\n"NOR,ob);
		count=0;
	}
	if(count<10&&count>0)	{
		message_vision(YEL"王夫人喝道："+ob->query("name")+"，上次我说的话难道忘了不成？下次不许再进这个屋！\n"NOR,ob);
	}
	if(count>=10)	{
	message_vision(RED"王夫人怒骂道：难道我说话如同放屁不成？！\n"NOR,ob);
	count=-1;
	kill_ob(ob);
	ob->fight_ob(this_object());
	}
	count=count+1;
	ob->set("oldsix_flag/wangfuren",count);
}
