// Room: /d/hangzhou/lu1.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条尘土飞扬的大路,向东就是天堂杭州的西门了.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qishi.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu2",
  "east" : __DIR__"ximen",
]));
	set("outdoors", "/d/hangzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
