// music   yangzhou's 店小二

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("店小二", ({ "xiaoer", "xiao", "waiter","xiao er","er" }) );
        set("gender", "男性" );
        set("age", 20);
        set("long",
                "眉清目秀的小伙计，整天笑嘻嘻的，忙得不亦乐乎。\n");
        set("mingwang",1);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");

        set("vendor_goods", ([
                     "包子":     __DIR__"obj/baozi",
                     "酒壶":     __DIR__"obj/jiuhu",
                     "鸡腿":     __DIR__"obj/jitui",
                     "盐水鹅" :  __DIR__"obj/yanshuie",
                     "花生米" :  __DIR__"obj/huashengmi", 
                             ]));


        set("inquiry", ([
              "zhongzhou": "你也是中州人？太巧了，我们同乡，你[1;33m去中州[0;36m吗？[0;37m\n",
               "中州":   "你也是中州人？太巧了，我们同乡，你[1;33m去中州[0;36m吗？[0;37m\n",
        ]) );


        setup();

        carry_object("/obj/cloth")->wear();
        add_money("coin", 50);
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}
void greeting(object ob)
{
if( !wizardp(ob) )
    {
        if( !ob || environment(ob) != environment() ) return;
      switch( (int) random(20)/10 ) {
                case 0:
                        say( "店小二打量了"+ob->query("name")+
   "一会，笑道：这位" + RANK_D->query_respect(ob)+ "，可能不是本地人吧？\n");
                        break;
                case 1:
                        say( "店小二将桌椅仔细擦了擦，说道：这位" + RANK_D->query_respect(ob)
                                + "，请坐请坐。\n");
                       break;
                           }
      if ( ob->query("age") <18 )
            {
             say( 
"店小二打量了"+ob->query("name")+"一会，笑道：这位" + RANK_D->query_respect(ob)+ "，可能不是本地人吧？\n");
            }      
      else {
            say( "店小二将桌椅仔细擦了擦，说道：这位" + RANK_D->query_respect(ob)+ "，请坐请坐。\n");
           }
   }
else
  {
  say("店小二满脸堆笑道: 是" + 
  ob->query("name")+RANK_D->query_respect(ob) + "来啦？请坐请坐.！\n");
      }
}
int accept_object(object who, object ob)
{
    
        if (ob->query("money_id") && ob->value() >= 100) 
        {
                tell_object(who, "小二一哈腰，说道：多谢您老，楼上有请。\n");
                who->set_temp("rent_paid",1);
                return 1;
        }
        return 0;
}
