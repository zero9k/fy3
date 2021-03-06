// master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("慕容博",({"murong bo","murong","bo"}));
        set("gender", "男性" );
	set("age",40);
        set("str", 27);
        set("cor", 30);
        set("cps", 27);
        set("int", 24);
	set("mingwang",1000000);
	set("max_force",3000);
	set("force",3000);
	set("force_factor",150);
	set("max_kee",2000);

        set("long",
                
	"面色白净的中年汉子，眉宇之间隐隐透出杀气。\n");

	create_family("姑苏慕容",1,"传人");

	set("combat_exp",5000000);
        set("score", 200000);

	set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
		(: perform_action,"unarmed.canhezhi" :),
		(: perform_action,"unarmed.tanyunshou" :),
        }) );

	set_skill("unarmed",200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("force",200);
	set_skill("daoxuexinde",100);
	set_skill("foxuexinde",100);
	set_skill("literate",100);



	set_skill("murongquanfa",200);
	set_skill("murongxinfa",200);
	set_skill("murongshenfa",200);
	set_skill("douzhuanxingyi",200);
	map_skill("unarmed","murongquanfa");
	map_skill("parry","douzhuanxingyi");
	map_skill("force","murongxinfa");
	map_skill("dodge","murongshenfa");

        setup();
	carry_object(__DIR__"obj/shan")->wear();
}

void attempt_apprentice(object ob)
{
	if(ob->query("mingwang")<100000)	{
	command("say "+RANK_D->query_respect(ob)+"似乎还没有在江湖上闯出什么名堂吧。");
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
 
