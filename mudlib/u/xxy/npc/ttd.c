inherit NPC;
inherit F_SAVE;

void create()
{
  set_name("花剑影",({"hua jianying"}));
  set("title","流星赶月");
  set("age",35);
  set("long","中等身材,白净脸皮,一副牙齿向外突了一寸，
一个鼻头低陷了半寸,他手中拿的是一副流星锤.\n");
  set("combat_exp",20000);
  set_skill("hammer",30);
  set_skill("parry",30);
  set_skill("dodge",30);
  set_skill("force",30);
  set_skill("unarmed",30);

  set("chat_chance",8);
  set("chat_msg",({
  "老大说,劫富济贫,我们就是穷人啊,这话真是有道理.\n",
  "依我看,还是把[擅闯者死]改为[非请莫入]的好.\n",
  "二哥搬那块石碑的时候,砸伤了脚,这几天行动不便.\n",
   }));
  set("inquiry",([
 "让路":"给钱,给钱就让你过去.给东西也成.",
  ]));
	setup();
 carry_object("/obj/armor/cloth")->wear();
 
}
void init()
{ object ob;
  ::init();
 if (interactive(ob=this_player())&&!is_fighting()) {
   remove_call_out("greeting");
   call_out("greeting",1,ob);
   }
}
void greeting(object ob)
{
  object npc;
  string str;
 if (!ob||environment(ob)!=environment()) return;
  npc=load_object("/d/new/robber/npc/robber1");
  str=npc->query("banghui");
command("say the banghui is "+str+".\n");
 if (ob->query("banghui")!=str)    {
  command("say 劫富济贫,替天行道,快给钱.\n");
  command("guard north");
  return;
            }
 command("say 原来是本帮弟兄,老大等你好久了.\n");
  return;
}
int accept_object(object me,object obj)
{
  if (obj->value()<10000)    {
  command("say 糊弄谁啊,一两金子,快,不然不给过.\n");
   return 0;        }
  command("guard cancel");
  message_vision("$N让开北面的路,让$n过去.\n",this_object(),me);
  return 1;
}

