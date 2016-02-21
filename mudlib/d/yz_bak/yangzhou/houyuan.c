// Room: /d/yangzhou/houyuan.c

inherit ROOM;

void create()
{
	set("short", "明月酒楼的后院");
	set("long", @LONG
	这里是明月酒楼的后院，一般只供酒店自己人休息用，这里
常常住了些到五湖四海的商人，也都是酒店的老主顾，和这儿的主人
也一向交好，常帮忙捎些货物过来。

LONG
	);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"startroom",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
