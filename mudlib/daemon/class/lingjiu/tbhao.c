// /d/lingjiu/npc/tbhao.c 昊天部 余婆婆
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("余婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
	    "她是"+HIC"「灵鹫宫」"NOR+"九天九部中昊天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", HIC"昊天部首领"NOR);
	set("gender", "女性");
	set("age", 60);
        set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("kee", 1300);
	set("max_kee", 1300);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 80);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	
        set_skill("sword",100);

	set_skill("liuyang-zhang",80);
        set_skill("lingbo-steps",80);
        set_skill("duzun-gong", 70);
        set_skill("tianyu-qijian", 70);

	map_skill("force", "duzun-gong");
	
        map_skill("dodge", "lingbo-steps");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");


	create_family("灵鹫宫",4,"弟子");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.san" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
            }) );
	setup();
 	carry_object("/obj/weapon/sword")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/d/lingjiu/obj/jiudai");
        add_money("silver",25);
}

void init()
{
        object ob;

        ::init();

        if( interactive(ob=this_player()) && !is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object ob)
{
	string family;

	family=(string)ob->query("family/family_name");
	if(family=="灵鹫宫")
	command("say "+ob->query("name")+"辛苦了，快回宫歇歇吧。");
else
	command("say 这位"+RANK_D->query_respect(ob)+"可是来拜师的？"
	+"那就拜"+RANK_D->query_self(this_object())+"我吧。");
}

void attempt_apprentice(object ob)
{
	message_vision("余婆婆垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
	command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
}
