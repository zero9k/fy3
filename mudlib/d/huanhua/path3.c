// Room: /d/new/huanhua/path3.c

inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
院中小径,由五色石子铺就.两边的芭蕉,紫琼的枝叶不时伸到路中.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"path2.c",
  "north" : __DIR__"path4.c",
]));
	set("outdoors", "/d/new");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
