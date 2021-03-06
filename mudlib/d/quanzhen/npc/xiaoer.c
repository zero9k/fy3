inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("店小二",({"xiao er","xiaoer"}));
	set("age",16);
	set("combat_exp",2000+random(2000));
	set("long","精明鬼精的小伙子。\n");
	set("area_name","长安镇酒楼");
        set("vendor_goods", ([
                "jitui":__DIR__"obj/jitui",
 		"kaoya":__DIR__"obj/kaoya",
               "jiudai":__DIR__"obj/jiudai",
                "baozi":__DIR__"obj/baozi",
        ]));

	setup();
	carry_object("/obj/cloth")->wear();
}

void init()
{
        object area,ob;
        area=new("/obj/area");
        area->create(query("area_name"));
        set("banghui",(string)area->query("banghui"));
        destruct(area);
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来打个尖，歇歇脚吧。\n");
                        break;
                case 1:
                                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}