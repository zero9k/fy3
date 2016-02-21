// Room: /u/uuui/xuedao/xuedao1.c

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
走到这里似乎开阔了许多，空地四周也种了些很普
通的花草，但却象很长时间没有人修整过。再往前就能
看见一个石洞。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xuedaomen/1");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xuedao0",
  "south" : __DIR__"xuedao2",
  "west" : __DIR__"xuedao4",
]));

	setup();
	replace_program(ROOM);
}
