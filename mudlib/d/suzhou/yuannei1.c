// Room: /d/suzhou/yuannei1.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条青石板铺成的走廊，东西走向。西面出拙政园的大门紧锁，看来想要出
去只好顾技重施爬墙出去了。东面是个四合大院，静悄悄也不知是什么所在。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "suzhou");
	set("objects",([
		__DIR__"npc/wushi":2,
]));
	set("exits",([
		"east":__DIR__"tbgju",
	]));
	setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string dir)
{
        object me=this_player();

        if( !living(me))        return 0;
        if( ! dir || (dir!="weiqiang"&&dir!="围墙"))
                return notify_fail("你要爬什么？\n");
        if( (int)me->query("kee")<50)
                return notify_fail("你的气力不够，爬不动。\n");
        if( (int)me->query_skill("dodge")<50)
                return notify_fail("你的轻功太低了。\n");
	message_vision("$N沿着围墙爬了出去。\n",me);
	me->move(__DIR__"zhuozhengmen");
        return 1;
}

int valid_leave(object me,string dir)
{
	object npc;

	npc=present("huyuan wushi",this_object());
	if(dir=="east" && objectp(npc) && living(npc))
		return notify_fail("护院武师喝道：先过了我着关！\n");
	return ::valid_leave(me,dir);
}

