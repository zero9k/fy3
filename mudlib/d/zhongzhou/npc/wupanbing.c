inherit NPC;

void create()
{
  set_name("巫攀冰",({"wu panbing","wu"}));
  set("gender","男性");
set("age",56);
set("nickname","帐房先生");
set("combat_exp",6000);
set_skill("unarmed",40);
set_skill("parry",40);
set_skill("dodge",40);
set_skill("literate",20);
set("chat_chance",5);
set("chat_msg",({
"巫攀冰拿笔杆敲了敲脑袋,一副恍然大悟的模样.\n",
"巫攀冰使劲翻动着三尺厚的帐本,终于累倒在地.\n",
"巫攀冰道:中医之中,要数[本草纲目]为一绝了.\n",
}));
setup();
carry_object("/obj/armor/guardsuit")->wear();
}
