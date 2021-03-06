// Room: /d/suzhou/chengbeijie4.c

inherit ROOM;

void create()
{
	set("short", "城北街");
	set("long", @LONG
你刚走到这，就听到西边隐隐传来钟声，其中似乎还渗杂着“咚咚”的木鱼
之声。你顺着响声望去，但见眼前一座老高的寺门，门匾上三个金光大字“报恩
寺”。你往东边看去，只见到粉墙黛瓦、栗柱灰砖的一座庄园。街道南北延伸，
再往北则是北平门了。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" :__DIR__"chengbeijie3",
		"north" :__DIR__"beipingmen",
		"west" :__DIR__"baoensi",
		"east" :__DIR__"zhuozhengmen",
]));
	set("objects",([
		"/npc/man3":2,
	]));
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
