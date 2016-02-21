// music   yangzhou's 兵勇

inherit NPC;

void create()
{
        set_name("城卫", ({ "chengwei", "bing", "wei" }) );
        set("gender", "男性" );
        set("age", 25);
        set("long",
                "比较高级的守城卫士。\n");
        set("mingwang", 1);
        set("combat_exp", 10000);
	set_skill("blade",60);
	set_skill("parry",60);
	set_skill("unarmed",60);
        set_skill("dodge",60);
        set("max_kee",600);
        set("kee",600);
        set("str", 30);
        set("cor", 20);
        set("con", 2);
        set("int", 2);
        set("attitude", "peaceful");
        setup();
        carry_object("/obj/armor/tiejia")->wear();
        carry_object("/obj/weapon/changdao")->wield();
        add_money("silver",20);
}
