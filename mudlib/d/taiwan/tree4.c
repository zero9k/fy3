// Room: /d/taiwan/tree4.c

inherit ROOM;

void create()
{
	set("short", "风波林");
	set("long", @LONG
抬眼望去,四面都是高高低低的树林.回头的路已经看不到了,前面的
路隐没在深深的茅草中.远处隐隐传来一阵女人的哭泣.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"tree3",
  "north" : __DIR__"tree5",
  "west" : __DIR__"tree5",
  "east" : __DIR__"tree4",
]));
	set("outdoors", "/d/taiwan");

	setup();
	replace_program(ROOM);
}
