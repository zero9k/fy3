inherit NPC;
void create()
{
    set_name("阎鬼鬼",({"yan guigui","shenmo"}));
        set("shen_type",-1);
    set("gender","男性");
    set("age",43);
    set("str",23);
    set("title","铁骑神魔");
    set("per",20);
    set("shen_tpye",-1);
    set("combat_exp",50000);
    set("long","权力帮手下,十九神魔之一。！.\n");
    set_skill("parry",60);
    set_skill("dodge",50);
    set_skill("unarmed",60);
    set_skill("force",60);
    set_skill("whip",100);
    setup();
add_money("silver",15);
carry_object("/d/obj/weapon/whip/whip")->wield();
}
