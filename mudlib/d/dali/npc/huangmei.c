// huangmei.c

inherit NPC;

void create()
{
	set_name("黄眉大师", ({ "huangmei dashi", "dashi", "huangmei" }));
	set("age", 69);
	set("gender", "男性");
	set("long", "这是一个满脸皱纹、身形高大的老僧。这老僧两道焦黄长眉，
眉尾下垂，是拈花寺主持。\n");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 69);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_kee", 1500);
	set("max_gin", 1000);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 150);
	set("combat_exp", 1000000);

	set_skill("force", 110);
	set_skill("hunyuan-yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin-shenfa", 110);
	set_skill("parry", 110);
	set_skill("unarmed",110);
	set_skill("nianhua-zhi", 110);
	set_skill("sanhua-zhang", 110);
	set_skill("fengyun-shou", 110);
	set_skill("longzhua-gong", 110);
	set_skill("foxuexinde", 110);
	set_skill("literate", 110);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "sanhua-zhang");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	setup();
	carry_object("/obj/cloth")->wear();
}

