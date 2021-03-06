// thd:kitchen.c
// 97.7.14 by Aug

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是桃花庄的厨房。小锅，小灶看来都十分精巧。因为桃花岛的人
不多，所以桃花岛的伙食重精不重多。黄岛主的烹调水平更是别具一格，
不落俗套，但要吃到他亲手烹制的菜肴可实在不容易。你要东西吃可以问
哑仆要(list)(yao)。屋角摆着口大水缸，你可以从中舀水来喝。
LONG
	);

	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/pot" :  1,
		__DIR__"npc/yapu6": 1,
	]));

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"in_road2",
	]));

	set("no_fight", 1);

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_drink", "drink");	
}

int do_drink(string arg)
{
	int current_water;
	int max_water;
	object me;

	if(arg!="water") 
	{
		write("你要喝什么？\n");
		return 1;
	}

	me = this_player();
	current_water = me->query("water");
	max_water = me->query("str")*10 + 100;
	if (current_water<max_water) 
	{
		me->set("water", current_water+30);
		message_vision("$N从大水缸里舀了一杯水喝。\n", me);
	}
	else 
		write("你已经喝的太多了。\n");

	return 1;
}

int valid_leave(object me, string dir)
{
  if(dir!="west") return ::valid_leave(me, dir);

  if((present("meat", me))||(present("doufu", me))||(present("zhou", me))||(present("baicai", me)))
    return notify_fail("哑仆双手一拦，指指你怀中的食物，不让你出去。\n");
  else
    return ::valid_leave(me, dir);
}

