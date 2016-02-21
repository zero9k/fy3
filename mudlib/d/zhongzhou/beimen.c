// Room: /d/zhongzhou/beimen.c

inherit ROOM;

void create()
{
	set("short", "中州北门");
	set("long", @LONG
这里已经到了中州的北门了，高高的城墙的砖缝里长满了草。走
过城门，再过了护城河，就是城外了。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/quanzhou/npc/bing.c" : 2,
]));
	set("outdoors", "/d/zhongzhou");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"to_zhongzhou3",
  "south" : __DIR__"wendingbei4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
