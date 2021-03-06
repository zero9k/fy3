inherit NPC;

void create()
{
   set_name("子鼠", ({ "mouse","laoshu" }) );
   set("race", "野兽");
   set("age", 6);
   set("long", "尖尖的嘴巴,两边拖着瘦硬的胡须。\n");
   
   set("str", 14);
   set("cor", 24);
   set("combat_exp",5000);
   set("kee",300);
   set("max_kee",300);

   set("limbs", ({ "头部", "身体", "尾巴", "左前爪","右前爪" "左后爪","右后爪" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 5);
   set("chat_msg", ({
  "老鼠的两只小眼珠在咕噜噜地转个不停.\n",
  "老鼠晃了晃尾巴,举起前爪在嘴边舔了几下.\n",
  "老鼠吱吱地叫了两声.\n",
 }));
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 20);

   setup();
}

void die()
{
  message_vision("$N吱吱叫了一阵,满地乱窜,一眨眼不见了.\n",this_object());
  new(__DIR__"obj/clarv.c")->move(environment(this_object()));
  destruct(this_object());
  return;
}