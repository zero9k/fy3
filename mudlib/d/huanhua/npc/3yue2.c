inherit NPC;
int play();

void create()
{
  set_name("������", ({"wen yanyang","wen"}));
        set("shen_type",1);
  set("gender", "����");
  set("combat_exp", 20000);
  set("title","�ٽ�");
    set("long","�������͵ĵ���֮һ!\n");
  set("age", 23);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set_skill("sword",60);
    set_skill("dodge",80);
    set_skill("parry",20);
    set_skill("literate",100);

  setup();
  set("chat_chance", 5);
  set("chat_msg", ({ (: play :) }));
  carry_object(__DIR__"obj/yangqin")->wear();
}
int play()
{
   if (present("yang qin",this_object()))
          command("play yang qin");
   else command("sigh");
   return 1;
}
int accept_fight(object me)
{
    if (!present("sword",this_object()))
          new("/d/obj/weapon/sword/changjian")->move(this_object());
    command("wield sword");
    command("say ��������,����Ī��!\n");
    return 1;
}

