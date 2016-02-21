//music yangzhou' 书生

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("书生", ({ "shusheng","shu sheng", "sheng" }) );
	set("gender", "男性" );
	set("age", 26);
	set("int", 28);
        set("combat_exp",200);
	set("long",
		"是个久考不中，却又自命不凡的落魄书生。\n");

	set("attitude", "peaceful");
	set_skill("literate", 40);
        set_skill("parry",20);
	setup();
carry_object("/obj/cloth")->wear();

}
void init()
{
	object ob;
	        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{

        if( !ob || environment(ob) != environment() ) return;
	if(random(ob->query_kar())/2>15)	{
	tell_object(ob,CYN"书生悄悄说道：你我相见实为有缘，这本太湖旅游图就给你吧。\n"NOR);
	new(__DIR__"obj/taihutu")->move(ob);
	}
}
