inherit NPC;
void create()
{
    set_name("萧西楼",({"xiao xilou","xiao","man"}));
        set("shen_type",1);
    set("gender","男性");
    set("age",45);
    set("str",30);
    set("title","浣花剑派掌门");
    set("per",43);
    set("combat_exp",100000);
    set("long","二十年前,凭一剑平定内外浣花两派,天下七名剑之一.
他长髯飘飘,风度逼人.\n");
    set_skill("parry",100);
    set_skill("dodge",100);
    set_skill("unarmed",120);
    set_skill("force",120);
    set_skill("sword",110);
    setup();
add_money("silver",15);
carry_object("/d/obj/weapon/sword/changjian")->wield();
}
