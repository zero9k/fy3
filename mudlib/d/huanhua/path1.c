// Room: /d/huanhua/path1.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
院中小径,由五色石子铺就.两边的芭蕉,紫琼的枝叶不时伸到路中.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/new");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"xiaoyuan",
  "northwest" : __DIR__"path2",
]));

	setup();
	replace_program(ROOM);
}
