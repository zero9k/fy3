// Room: /d/suzhou/taijiannong1.c

inherit ROOM;

void create()
{
	set("short", "太监弄");
	set("long", @LONG
太监弄内各种菜馆不下十几家，是苏州城内有名的吃喝弄，所谓“吃煞太监
弄”便是它的真实写照。但你发现进出此弄的不少是衣冠楚楚的富家公子哥，似
乎此弄中还有别的蹊跷。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"taijiannong1",
		"east" :__DIR__"dacunlou1",
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
