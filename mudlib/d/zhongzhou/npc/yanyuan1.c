//yanyuan
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("女演员", ({ "yanyuan","woman"}));
	set("gender", "女性");
	set("age", 18);
	set("long", "戏院里的演员\n");
	
 	set("per" ,30);
	set("combat_exp",1000);
	set("mingwang",-1);
	set("attitude", "peaceful");
	 

	set_skill("unarmed", 10);
	set_skill("dodge", 30);
	set_temp("apply/attack", 5);
	set_temp("apply/defense",30);
	setup();
	carry_object("/obj/cloth")->wear();
        add_money("silver",5); 
}
void init()
{
        object ob;
        ob = this_player();
        ::init();
        if( interactive(ob) && !is_fighting() )
               {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
}
void greeting(object ob)
{
	if(ob->query("per")>=30 && ob->query("gender")=="男性")   
	say(HIY"女演员盯着你说道："+ RANK_D->query_respect(ob)+"看你相貌堂堂，做我们这行肯定能红！\n"NOR);
}


