// YinTianZheng.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;

void create()
{
    set_name("殷天正", ({"yin tianzheng", "yin", "tianzheng", }));
	set("rank_info/self","老夫");
	set("long",
        "他是一位身材魁梧的秃老者，身穿一件白色长袍。\n"
        "他长眉胜雪，垂下眼角，鼻子钩曲，犹如鹰嘴。\n"
	);
                                                          
	set("banghui","明教");
	set("bh_rank","白眉鹰王");
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 72);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("kee", 3500);
	set("max_kee", 3500);
	set("gin", 1500);
	set("max_gin", 1500);
	set("force", 3000);
	set("max_force", 3000);
                set("force_factor", 80);
                  set("combat_exp", 500000);
               set("score", 15000);

        set_skill("force", 160);
        set_skill("sanyang-shengong", 160);
        set_skill("dodge", 160);
	set_skill("tianlong-bu",160);
        set_skill("parry", 160);
	 set_skill("unarmed", 160);
        set_skill("literate", 100);
	set_skill("sougu", 200);

        map_skill("force", "sanyang-shengong");
        map_skill("parry", "sougu");
	map_skill("dodge","tianlong-bu");
	map_skill("unarmed","sougu");


	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}
int recognize_apprentice(object ob)
{
        string banghui;
        if(! stringp(banghui=ob->query("banghui")) ||
                banghui!=query("banghui"))
        return notify_fail(query("name")+"摇头道：你我非亲非故，"+
                RANK_D->query_self(this_object())+"如何敢当。\n");
	if(ob->query("score")<1000)
                return notify_fail(query("name")+"道：你还是多为本教做些实事吧。
\n");
        return 1;
}


