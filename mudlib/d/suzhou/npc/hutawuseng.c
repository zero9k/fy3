// music   yangzhou's 店小二

inherit NPC;

void create()
{
	set_name("护塔武僧",({"wuseng","wu seng","wu","seng"}));
	set("gender", "男性" );
	set("age", 20);
	set("long",
		"守护寺塔的武僧，长得甚是结实。\n");
	set("combat_exp",8000);
	set_skill("unarmed",50);
	set_skill("blade",50);
	set("mingwang",1);
	set_temp("apply/attack",30);
	set_temp("apply/defense",30);
	set_temp("apply/damage",10);
	set_skill("parry",50);
	set_skill("dodge",50);
	setup();
	carry_object(__DIR__"obj/qingbusengyi")->wear();
	carry_object(__DIR__"obj/jiedao")->wield();
}
