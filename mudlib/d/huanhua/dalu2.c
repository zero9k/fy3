// Room: /d/new/huanhua/dalu2.c

inherit ROOM;

void create()
{
	set("short", "大路");
	set("long", @LONG
一条人来人往的大路,来往人流,车辆不断.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"dalu3",
  "west" : __DIR__"dalu",
]));
	set("outdoors", "/d/new");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
