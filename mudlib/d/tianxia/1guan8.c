// Room: /d/tianxia/1guan8.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
一条长长的室内走廊，两边是一个个的小房间，走廊的顶很高，因
为长的原因，阳光照不到里面，所以两边壁上隔不多远就有油灯点着。
两边的房间中不时传来有人打呼声。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"sleeproom",
  "west" : __DIR__"1guan7",
  "east" : __DIR__"1guan9",
]));

	setup();
	replace_program(ROOM);
}
