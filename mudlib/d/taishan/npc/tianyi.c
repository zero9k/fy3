// tianyi.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("天乙道人", ({ "tianyi daoren", "daoren", "tianyi" }) );
        set("gender", "男性");
        set("class", "taoist");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("force", 1400);
        set("max_force", 1400);
        set("force_factor", 30);
        set("max_kee",1200);
        set("max_gin",800);
        set("combat_exp", 500000);
        set("shen_type", 1);

        set_skill("unarmed", 80);
	set_skill("kuaihuo-zhang",80);
        set_skill("sword", 80);
	set_skill("shibapan-jianfa",80);
        set_skill("force", 80);
	set_skill("panshi-neigong",80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
	set_skill("fengshenjue",80);

        map_skill("sword", "shibapan-jianfa");
        map_skill("parry", "shibapan-jianfa");
        map_skill("dodge", "fengshenjue");
	map_skill("force","panshi-neigong");
	map_skill("unarmed","kuaihuo-zhang");

        create_family("泰山派", 13, "弟子");
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
        if((int)ob->query("mingwang")<0)
        command("say 我泰山派弟子都是行侠仗义之辈，"+
        RANK_D->query_respect(ob)+"还做的不够啊。");
        else    {
        command("say 好啊，那我就收下你吧。");
       command("recruit " + ob->query("id") );
       ob->set("class","swordsman");
        }
}
