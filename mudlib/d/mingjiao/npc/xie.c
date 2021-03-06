// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;

void create()
{
    set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title",HIG "明教" HIY "金毛狮王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 3500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
        set("jiali",80);

        set("combat_exp",400000);
      set("score",15000);

       set_skill("force",150);
	set_skill("dodge", 140);
        set_skill("parry",150);
       set_skill("cuff",150);
      set_skill("jiuyang-shengong",150);
       set_skill("qishang-quan",150);
    	set_skill("literate", 100);

       map_skill("force","jiuyang-shengong");
	map_skill("cuff", "qishang-quan");
        map_skill("parry", "qishang-quan");


	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
	}) );

create_family("明教",2, "弟子");

	setup();

    	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}
void attempt_apprentice(object ob)
{
object me;
        mapping ob_fam, my_fam;
        string name, new_name;

        me = this_object();
        my_fam  = me->query("family");

        name = ob->query("name");

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "明教")

        {
                command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不
知此话从何谈起？");
                return;
        }
    
if(ob->query("score")<300)
        {
                command("say 你自问对本教尽心了吗?");
                return 0;
        }
        command("say 好，我就收下你.");
        command("recruit " + ob->query("id"));
}

