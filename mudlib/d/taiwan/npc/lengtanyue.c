#include <ansi.h>
inherit NPC;
void create()
{
    set_name("冷探月",({"leng tanyue"}));
    set("gender","男性");
    set("age",54);
    set("long","三十年前，[阴煞双凶]是横行绿林的大盗，
    自从投入幽冥一门以来，不再出现江河。\n");
    set("title",YEL"天煞"NOR);
    set("combat_exp",500000);
    set("kee",800);
    set("max_kee",800);
    set("force",800);
    set("max_force",800);
    set("force_factor",25);
    set("food",200);
    set("water",200);
    
    set("inquiry",([
    "幽冥山庄":"你现在呆的地方就是了。\n",
    "道心种魔大法":"我门中无上大法，可惜早几代就失传了.\n",
    ]));
    
        set("shen_type",-1);
    set("chat_chance",3);
    set("chat_msg",({
    CYN"冷探月取出把大砍刀掏起耳朵来.\n"NOR,
    CYN"听说我门中还有位长老,不过谁都没见过.\n"NOR,
    CYN"冷探月添添嘴唇道:他奶奶的,也不来个人给解解馋。\n"NOR,
    }));
    
    set_skill("dodge",50);
    set_skill("parry",50);
    set_skill("unarmed",50);
    set_skill("force",50);
    set_skill("literate",10);
    set_skill("guiyingmizong",50);
    set_skill("jiuyou-xinfa",50);
    set_skill("youming-zhang",50);
    
    map_skill("dodge","guiyingmizong");
    map_skill("unarmed","youming-zhang");
    map_skill("parry","youming-zhang");
    map_skill("force","jiuyou-xinfa");
  
    setup();
    add_money("silver",5);
 }
void init()
{
  object ob;
  ::init();
  if (interactive(ob=this_player())&&!is_fighting())  {
  	remove_call_out("greeting");
  	call_out("greeting",1,ob);
     }
  }
void greeting(object ob)
{
   if (!ob||environment(ob)!=environment())  return;
   if (ob->query("family/family_name")!=RED"幽冥山庄"NOR) {
   	kill_ob(ob);
   	return;
     }
   if (ob->query("combat_exp")>500000)
 command("say 您老来啦,宗主等你好久了!\n");
   else   {
 if (ob->query("gender")=="女性")
 command("say 小丫头你怎么现在才来,再不来宗主可发火了.\n");
 else
 command("say 你小子现在才到,看呆会宗主不剥了你皮.\n");
}
  return;
}
