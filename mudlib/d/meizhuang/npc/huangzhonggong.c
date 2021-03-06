// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黄钟公",({"huangzhong gong","huangzhonggong","gong"}));
	set("nickname","大庄主");
        set("gender", "男性" );
	set("age",65);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
	set("mingwang",1);
        set("int", 24);
    set("max_sen",500);
    set("eff_sen",500);
    set("sen",500);
    set("max_gin",500);
    set("eff_gin",500);
    set("gin",500);
	set("max_kee",2000);
	set("max_force",2000);
	set("force",2000);
	set_skill("foxuexinde",100);
	set_skill("daoxuexinde",100);
	set("force_factor",120);

	set("rank_info/respect","大庄主");

        set("long",
                
	"孤山梅庄的老大，面目很是慈祥。\n");

	create_family("孤山梅庄",1,"庄主");
	set("title","孤山梅庄");

	set("combat_exp",1000000);
        set("score", 200000);


	set_skill("sword",200);
	set_skill("unarmed",200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("force",200);
	set_skill("staff",200);
	set_skill("throwing",200);
	set_skill("blade",200);
	set_skill("literate",100);
	set_skill("xuantian-neigong",200);
	set_skill("xuantian-bu",200);
	set_skill("xuantian-quan",200);
	set_skill("qixianwuxing-jian",200);
	set_skill("pomopima-dao",200);
	set_skill("mantianxing",200);
	set_skill("jiangjun-zhang",200);
	map_skill("unarmed","xuantian-quan");
	map_skill("dodge","xuantian-bu");
	map_skill("force","xuantian-neigong");
	map_skill("parry","qixianwuxing-jian");
	map_skill("sword","qixianwuxing-jian");
        setup();
	carry_object(__DIR__"obj/qixianjian")->wield();
	carry_object(__DIR__"obj/sipao")->wear();
	add_money("gold",4);
}

void attempt_apprentice(object ob)
{
	if(ob->query_skill("xuantian-neigong",1)<100)	{
		command("say 这位"+RANK_D->query_respect(ob)+"的「玄天内功」还要多下些功夫啊。\n");
		return;
	}
        command("say 很好，" + RANK_D->query_respect(ob) + 
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
			ob->set("class","xiake");
}
 
