// YanYuan.c
// pal 1997.05.11

inherit NPC;

void create()
{
    set_name("严垣", ({ "yan yuan", "yan", "yuan", }));
	set("long",
        "他是一个矮矮胖胖的汉子，身穿一件白布长袍。\n"
        "他天生神力，手中的两头狼牙棒有万夫不当之勇，真是一条威风凛凛的汉子。\n"
	);

	set("banghui","明教");
	set("bh_rank","厚土旗掌使");
	set("gender", "男性");
	set("attitude", "friendly");
//    set("class", "bonze");

    set("age", 48);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 85);
	set_skill("hunyuan-yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin-shenfa", 85);
	set_skill("unarmed", 95);
	set_skill("jingang-quan", 95);
	set_skill("parry", 85);
	set_skill("foxuexinde", 85);
	set_skill("literate", 85);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "jingang-quan");
	map_skill("parry", "jingang-quan");

	setup();

//    carry_object("/d/mingjiao/obj/tiechan")->wield();
    carry_object("/d/mingjiao/obj/baipao")->wear();
}
