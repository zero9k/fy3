// banshanting.c 半山亭


inherit ROOM;

void create()
{
	set("short", "半山亭");
	set("long", @LONG
	这里是半山腰的一个小凉亭，游客们爬山爬的累了，就转个弯到这
里来坐一坐，歇一歇脚。从这里看下去，刚好可以看见翠屏峰的峰顶。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shijie5",
	]));

	set("objects",([
		__DIR__"npc/youke" : 2,
	]));

	setup();
	replace_program(ROOM);
}