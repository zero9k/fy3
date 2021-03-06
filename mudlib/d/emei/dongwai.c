// Room: /d/room/dongwai
inherit ROOM;

void create()
{
  set ("short", "仙峰石");
  set ("long", @LONG
沿山道而上,有一矩形巨石峙立在道旁,高10米,宽17米.石上刻有
清代诗人赵尧生楷书'南无普贤菩萨',此石古称仙圭石.石边藤蔓环绕
藤蔓后面好象有什么东西在闪光.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"jiulaofe",
]));
set("outdoors","/d/emei");
  set("item_desc", ([ /* sizeof() == 1 */
  "藤蔓" : "芊芊蔓蔓的山藤,看来有些年头了,不知道拉(la)开后有什么发现.
",
]));
  setup();
}
void init()
{
	add_action("do_la", "la");
}
int do_la(string arg)
{
    if(arg!="藤蔓") return 0; 
    message_vision("$N拉开藤蔓,连跌带爬的摔了进去！\n", this_player());
    this_player()->move(__DIR__"dongzhong"); 
    message_vision("$N狼狈不堪的从外面摔了进来,脸上沾满了青苔！\n", this_player());

    return 1;
}
