// Room: /d/hangzhou/dalu3.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这条小路沿着西湖婉转，两边植满梅树，小路尽头梅花掩映中一
座极大的庄院，那就是梅庄了。北面是个三叉路口。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hangzhou");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/meizhuang/xiaolu4",
  "north" : __DIR__"dalu2",
]));

	setup();
	replace_program(ROOM);
}
