// Room: /d/suzhou/tuoman/lukou.c

inherit ROOM;

void create()
{
	set("short", "路口");
	set("long", @LONG
路边种着几株大树，正好可以遮风挡雨。两边的山茶都是先前没有见过的。
你正自担心如何找到出路，忽听得东边隐隐传来少女的叹息之声。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west":__DIR__"hualin1",
		"east":__DIR__"huapu",
		"south":__DIR__"ru1",
		"north":__DIR__"ru3",
]));
	set("objects",([
		__DIR__"npc/beinu":2,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
