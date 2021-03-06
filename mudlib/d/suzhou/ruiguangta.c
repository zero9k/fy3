// Room: /d/suzhou/ruiguangta.c

inherit ROOM;

void create()
{
	set("short", "瑞光塔");
	set("long", @LONG
此塔是苏州城内最古老的塔，此塔建于三国时代。相传一位高僧来此传法时，
堂前突然出现一只白龟来听讲，庭院中的芍药花、合欢、双竹也好象在听法，被称
为“四瑞呈祥”，因而得瑞光之名。瑞光塔、盘门及吴门桥俗称为“盘门三景”。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" :__DIR__"panmen",
]));
	set("objects",([
	__DIR__"npc/eba":1,
	__DIR__"npc/enu":2,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
