// thd:fall.c
// 97.7.14 bu Aug

inherit ROOM;

void create()
{
      set("short", "千丈瀑");
	set("long", @LONG
这里是千丈瀑。这个瀑布当然不是真正的有千丈之高，但因为地势特
殊，落差极大，这个瀑布的气势极其磅礴，比之大陆名山大川的磅礴丝毫
不见逊色。你站在瀑布边上十丈之外，都能感受到那震耳欲聋的巨大声响
和那铺天盖地的水雾。特别引人注目的是瀑布中央的一块巨石，经过千百
年的冲击，它表面已经光滑的象冰。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

	set("detail", ([ /* sizeof() == 1 */
		"rock" : "你依稀可以在岩石上看到“独孤岩”三个字。\n",
      ]));

      set("exits", ([ /* sizeof() == 1 */
          "west" : __DIR__"table",
  	]));
      
	set("outdoors", "thd");

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me,ob;

	if((arg!="rock")&&(arg!="独孤岩")) return 0;
	
	me=this_player();

	message_vision("$N飞身一跃，跳上独孤岩。\n",me);

	if(me->query_skill("dodge")<20)
		message_vision("可岩石上太滑了，$N不得不又跳了回来。\n",me);
	else
		me->move(__DIR__"rock");

	return  1;
}