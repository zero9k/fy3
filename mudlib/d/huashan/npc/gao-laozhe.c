// gao-laozhe.c

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("华山高老者",({"gao laozhe","gao"}));
        set("title", HIR"华山第十二代长老"NOR);
        set("long", 
"他就是华山的长老高老者。一副浑不在乎的模样，开朗乐天，万事不萦怀，\n"
"但事事追随他的师兄矮老者。\n");
        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        
        set("kee", 3800);
        set("max_kee", 3800);
        set("gin", 3600);
        set("max_gin", 2000);
        set("force", 2400);
        set("max_force", 2400);
        set("force_factor", 100);

        set("combat_exp", 1250000);
        set("score", 200000);

        set_skill("force", 160);
        set_skill("blade", 170);
        set_skill("dodge", 170);
        set_skill("parry", 170);
        set_skill("unarmed", 170);
        set_skill("zixia-shengong", 200);
        set_skill("poyu-quan", 160);
        set_skill("fanliangyi-dao", 170);
       set_skill("feiyan-huixiang",160);
        set_skill("literate", 100);


        map_skill("force", "zixia-shengong");
        map_skill("dodge", "feiyan-huixiang");
        map_skill("parry", "fanliangyi-dao");
        map_skill("blade", "fanliangyi-dao");
        map_skill("unarmed", "poyu-quan");

        create_family("华山派", 12, "弟子");

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sanshen" :),
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query_skill("zixia-shengong", 1) < 60) {
                command("say 我华山派乃内家武功，最重视内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在紫霞神功上多下点功夫？");
                return;
        }
        if ((int)ob->query("mingwang") < 100000) {
                command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        if (ob->query_spi() < 25) {
                command("say 我华山武功主要的就是靠天资。");
                command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，灵性却是半点也马虎不得。");
                command("say " + RANK_D->query_respect(ob) + "的灵气不足，学我的武功还不行。");
                return;
        }
        command("say 好吧，老头子就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("class","xiake");
}
