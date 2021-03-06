// shantang.c

inherit ROOM;

void create()
{
	set("short", "膳堂");
	set("long", @LONG
	这里是全真教的膳堂，是弟子们用餐的地方。这个堂很大，整齐
地摆放着一排一排的桌椅。现在桌椅上三三两两地坐着全真弟子，有的正
在用餐，有的低头谈笑。看着可口的饭菜，你忍不住也想叫(order)一份。
LONG
	);

	set("exits",([
		"north" : __DIR__"xiuxishi",
		"east" : __DIR__"chufang",
		"northwest" : __DIR__"wuchang2",
	]));

	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
	object me=this_player();
	object food;
	object water;

	if (arg)  return notify_fail("这样东西这里没有啊。\n");

	message_vision("火工道人连忙把一碗米饭和一碗水拿了给$N\n",me);

	food=new(__DIR__"obj/rice");
	water=new(__DIR__"obj/bowl");
	food->move(me);
	water->move(me);
       	return 1; 
}

int valid_leave(object me,string dir)
{
	me=this_player();
        if(( dir=="north" || dir=="northwest") 
	&& (present("bowl",this_player()) || present("rice",this_player()))) 
             return notify_fail("火工道人说道：食物和饮水不能带出膳堂去。\n");
        return ::valid_leave(me,dir);
}
