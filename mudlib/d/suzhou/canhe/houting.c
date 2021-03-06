// Room: /d/suzhou/canhe/qianting.c

inherit ROOM;

void create()
{
	set("short","后厅");
	set("long", @LONG
厅内布置简单的令你难以相信，除了桌子椅子这些必备的家俱之，整个厅内
竟无其它任何东西。你一走进这里，就觉的这儿实在安静的有些过份，忍不住就
想大叫几声。
LONG
	);
	set("move",0);
	set("exits", ([ /* sizeof() == 1 */
		"west":__DIR__"dating",
]));
	set("objects",([
		__DIR__"npc/feng":1,
]));
        set("item_desc",([
                "桌子" : "这张桌子(zhuozi)似乎没什么特别之处。\n",
                "zhuozi":"这张桌子似乎没什么特别之处。\n",
		"椅子" : "这张椅子(yizi)似乎可以移动(yi)。\n",
		"yizi" :"这张椅子似乎可以移动(yi)。\n",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_move","yi");
	add_action("do_pull","chou");
}
int do_pull(string str)
{
	object me;
	me=this_player();
	if(!str)	{
		tell_object(me,"你要抽什么？\n");
		return 1;
			}
	if(str=="木板"||str=="muban")	{
		if (query("move")==0)	{
			tell_object(me,"椅子还在木板上面，没法抽！\n");
			return 1;
					}
		if (query("exits/down"))	{
			tell_object(me,"木板已经抽出来了。\n");
			return 1;
						}
		message_vision("$N小心翼翼的将木板抽出。\n",me);
		tell_object(me,"你发现底下是个青砖铺成的石梯。\n");
		set("exits/down",__DIR__"miru1");
		return 1;
					}
	tell_object(me,"这个东西不能抽出来。\n");
	return 1;
}
int do_move(string str)
{
	object me;
	me=this_player();
	if(!str)	{
		tell_object(me,"你要移什么？\n");
		return 1;
			}
	if (str=="椅子"||str=="yizi")	{
		if(query("move")==1)	{
			tell_object(me,"椅子已经移过啦！\n");
			return 1;
					}
		message_vision("$N使出吃奶的劲把椅子移到了一边。\n",me);
		tell_object(me,"你发现椅子移走后，下面有块木板(muban)。\n");
		set("move",1);
		set("item_desc",([
		"木板" : "这块木板(muban)好象可以抽(chou)出来。\n",
		"muban" :"这块木板好象可以抽(chou)出来。\n",
			"椅子" : "椅子(yizi)已经被人移到了一边。\n",
			"yizi" : "椅子已经被人移到了一边。\n",
				]));
		return 1;
					}
	tell_object(me,"这样东西不可以移动。\n");
	return 1;
}
int valid_leave(object me,string dir)
{
	if(dir=="down")	{
		this_object()->delete("exits/down");
		call_out("speak",1,me);
		set("move",0);
			}
	return 1;
}
int speak(object me)
{
	write("只听得几声清响，屋内又恢复原样。\n");
	return 1;
}
