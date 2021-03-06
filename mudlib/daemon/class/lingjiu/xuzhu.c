// /NPC xuzhu.c
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(string name);
void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",
	    "这是一个二十五六岁的年轻人, 浓眉大眼,\n"+
	    "大大的鼻子扁平下塌, 容貌颇为丑陋. \n"+
	    "身穿一件华贵雅致的长袍, 倒使他更显几分精神.\n"+
	    "他就是天山童姥的救命恩人.\n");
	set("title", HIC"灵鹫宫尊主"NOR);
	set("gender", "男性");
	set("per", 16);
	set("age", 26);
	set("nickname", HIR "梦郎" NOR);
	set("mingwang",5000);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("max_kee", 3000);
	set("max_gin", 1200);
	set("force", 2500);
	set("max_force", 2500);
	set("force_factor", 80);

	set("combat_exp", 2500000);
	set_skill("force", 150);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
          set_skill("sword", 150);
	set_skill("parry", 150);


	set_skill("liuyang-zhang",150);
        set_skill("lingbo-steps",150);
	set_skill("duzun-gong", 150);
        set_skill("tianyu-qijian", 150);

	map_skill("force", "duzun-gong");

        map_skill("dodge", "lingbo-steps");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
        map_skill("sword", "tianyu-qijian");

        set("inquiry", ([
		"灵鹫令" : (: ask_me, "lingjiu" :),
		"进修" : (: ask_me, "lingjiu" :),
		"小院" : (: ask_me, "lingjiu" :),
        ]));
	set("ling_count", 1);


	create_family("灵鹫宫",2,"尊主");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),
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
 	carry_object("/d/lingjiu/obj/changpao")->wear();
        carry_object("/d/lingjiu/obj/jiudai");
        add_money("silver",50);
}
string ask_me(string name)
{
	mapping fam;
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";

	if (query("ling_count") < 1)
		return "你来得不是时候，已经有人在练功了。";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("ling_count", -1);

	message_vision("虚竹给$N一个" + ob->query("name") + "。\n", this_player());

	return "拿去吧。";
}
void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("duzun-gong", 1) < 65) 
           {
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	   }  
else {
		message_vision("虚竹垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
       command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "officer")
			ob->set("class", "officer");
       return;}
}
