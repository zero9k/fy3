inherit NPC;
void create()
{
    set_name("唐方",({"tang fang","girl"}));
        set("shen_type",-1);
    set("gender","女性");
    set("combat_exp",20000);
    set("attitude","friendly");
    set("age",16);
    set("long","唐门最年轻神密的弟子,她黑白分明的眼,
飞瀑般流泄而下的柔发,窈佻的身影,绝对是唐门最美的一个.\n");
    set_skill("unarmed",30);
    set_skill("parry",40);
       set_skill("dodge",100);
       set_skill("throwing",100);
       set_skill("force",50);
       set_skill("literate",100);
    setup();
add_money("silver",3);
carry_object(__DIR__"obj/feidao")->wear();
}
