// jiading.c

inherit NPC;
string kill_passenger(object who);
void create()
{
        set_name("护法僧", ({ "seng","heshang" }) );
        set("gender", "男性" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);
	set("area_name","泉州开元寺");

        set("max_force", 100);
        set("force", 100);
        set("force_factor", 10);

        set("attitude", "heroism");

        set("long",@LONG
手持钢刀的僧人,为保证佛门清净,所以有些僧人习武护寺。
LONG);

        set("combat_exp", 20000);
        set("score", 50);
        set_skill("blade",60);
        set_skill("unarmed", 50);
	set_skill("dodge", 40);
	set_skill("parry", 50);
	setup();
        add_money( "coin" , 50);
        carry_object("/d/quanzhou/obj/blade")->wield();
        carry_object("/d/quanzhou/obj/jiasha")->wear();
}

void init()
{
        object area,ob;
        area=new("/obj/area");
        area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
	::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checklooking");
                call_out("checklooking", 1, ob);
        }
}

void checklooking(object ob)
{
	string banghui;
	banghui=(string)ob->query("banghui");
	if(banghui && banghui==(string)query("banghui"))	return;

	 if ( random((int)ob->query("per")) < 5  )
	 {
	command("say 站住！你干什么的。");
	command("say 看你那贼眉鼠眼，尖嘴猴腮的样儿，决不是什么好东西！");
        kill_ob(ob);
	 }
       else 
           command("say 阿弥佗佛,施主请进大殿上香.\n");	
}

