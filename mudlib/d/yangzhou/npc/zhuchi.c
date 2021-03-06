//Mr.music yangzhou 大明寺住持

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("惠通", ({ "zhuchi", "zhu chi","huitong" }) );
        set("gender", "男性" );
        set("age", 54);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("mingwang",1);
        set("max_force", 4000);
        set("force", 3000);
        set("force_factor", 3);

        set("rank_info/respect", "圣僧");

        set("long","这位就是大明寺的住持\n");

        create_family("大明寺", 9, "住持");

        set("combat_exp", 10000);
        set("score", 2000);

        set_skill("unarmed", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("sword", 90);
        set_skill("force", 90);
        set_skill("literate", 100);
        set_skill("throwing",150);
        set_skill("qiankunyizhi",150);

        map_skill("throwing","qiankunyizhi");

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object(__DIR__"obj/zhuye")->wield();
}

void attempt_apprentice(object ob)
 {
        command("say " + RANK_D->query_respect(ob) + 
 "六根清静，佛源久长，真是佛门之幸。\n");
        command("recruit " + ob->query("id") );
 }

 void recruit_apprentice(object ob)
 {
        if( ::recruit_apprentice(ob) )
                ob->set("class", "heshang");
 }
 

void init()
{
        ::init();
        add_action("do_ketou", "ketou");
}


int do_ketou()
{
  object ob;
  ob=this_player(1);

  if((ob->query("family/master_name"))=="惠通")
   {
    message_vision("\n$N恭恭敬敬地向惠通磕了个响头，叫道：「师父！」。\n", 
this_player(1));

      if(ob->query("kee")<50)  ob->add("kee",1);
      if(ob->query("gin")<30)  ob->add("gin",1);
      if(ob->query("sen")<30)  ob->add("sen",1);
      if(ob->query("atman")<30)  ob->add("atman",1);

      if(ob->query("food")<50)  ob->add("food",((int)ob->query("str")-10)*5);
     if(ob->query("water")<90)  ob->add("water",((int)ob->query("str")-10)*5);

    return 1;
   }
   message_vision("\n$N恭恭敬敬地向住持磕了个头。\n", this_player(1));
   return 1;
  }

