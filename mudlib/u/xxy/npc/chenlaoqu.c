inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("陈老曲",({"chen laoqu","chen","laoqu"}));
        set("nickname","嗜酒如命");
        set("gender","男性");
        set("long","陈老板醉心于酒,对生意反而不那么在意.从他
异于常人的酒糟鼻和一讲话就满屋子的酒气,
不难看出他平常为人!\n");
        set("age",56);
        set("str",20);
        set("combat_exp",200000);
        set_skill("unarmed",40);
        set_skill("parry",40);
        set_skill("literate",40);
        set_skill("force",40);
        set("vendor_goods",([
                  "jiutan":__DIR__"obj/jiutan",
       ]));
     setup();
     carry_object("/obj/cloth")->wear();
     add_money("silver",30);
}
void init()
{   ::init();
       add_action("do_vendor_list","list");
}
 