// tianmen.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("天门道人", ({ "tianmen daoren", "daoren", "tianmen" }) );
        set("gender", "男性");
        set("title", HIG"泰山派第十三代掌门"NOR);
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("force", 2400);
        set("max_force", 2400);
        set("force_factor", 100);
        set("max_kee",2000);
        set("max_gin",1200);
        set("combat_exp", 1400000);
        set("shen_type", 1);

        set_skill("unarmed", 200);
	set_skill("kuaihuo-zhang",200);
        set_skill("sword", 200);
	set_skill("shibapan-jianfa",200);
        set_skill("force", 200);
	set_skill("panshi-neigong",200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
	set_skill("fengshenjue",200);

        map_skill("sword", "shibapan-jianfa");
        map_skill("parry", "shibapan-jianfa");
        map_skill("dodge", "fengshenjue");
	map_skill("force","panshi-neigong");
	map_skill("unarmed","kuaihuo-zhang");

        create_family("泰山派", 13, "掌门");
        setup();

carry_object("/obj/weapon/sword")->wield();
carry_object("/d/wudang/npc/obj/greyrobe")->wear();
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
        if(family!="泰山派")
                command("say "+RANK_D->query_respect(ob)+
                "若是加入我泰山派，必能光大本派！");
        else
                command("nod "+ob->query("id"));
}

void attempt_apprentice(object ob)
{
        if((int)ob->query("mingwang")<50000)
        command("say 我泰山派弟子都是行侠仗义之辈，"+
        RANK_D->query_respect(ob)+"还做的不够啊。");
	else if((int)ob->query_skill("panshi-neigong",1)<100)
	command("say 你的本门心法还得多多练习。");
        else    {
        command("say 好啊，那我就收下你吧。");
       command("recruit " + ob->query("id") );
       ob->set("class","swordsman");
        }
}

