// Room: /d/huanggon/tianjin.c

inherit ROOM;

void create()
{
	set("short", "王府天井");
	set("long", @LONG
说是天井,其实是个大院子,空空的场地铺上白色石板,一边是口水
井,京中的富贵人家,时常叫了戏班子在家中出演,那就少不了这样的空
场,南边是大厅,北边是内厅.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"xiaogardon",
  "south" : __DIR__"kangdating",
  "north" : __DIR__"kangneiting",
]));

	setup();
	replace_program(ROOM);
}
