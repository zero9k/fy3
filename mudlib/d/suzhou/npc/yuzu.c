// guard.c

#include <ansi.h>

inherit NPC;


void create()
{
	set_name("狱卒",({"yuzu"}));
	set("gender", "男性" );
	set("age",24);
	set("str",50);
	set("cor", 30);
	set("mingwang",-1);
	set("cps", 30);
	set("int",30);
	set("con",50);
	set("long",
	"英俊潇洒，貌似潘安。你最好还是不要招惹他。\n"
	);
	set_temp("apply/attack",40);
	set_temp("apply/defense",40);
	set_temp("apply/damage",20);
	set_temp("apply/armor",40);
	set("combat_exp",10000);
	set_skill("blade",50);

	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
	"狱卒笑骂道：你当这里是什麽地方，敢来这里撒野？\n",
	"狱卒叫道：还是住手吧，我看你非我敌手。\n",
	}) );

	set_skill("dodge",50);
	set_skill("parry", 50);
	
	setup();
	
	carry_object("/obj/weapon/blade")->wield();
	carry_object("/obj/cloth")->wear();
}
