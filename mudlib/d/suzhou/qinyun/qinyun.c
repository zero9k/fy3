// Room: /u/oldsix/room1/qingyun.c

inherit ROOM;

void create()
{
	set("short", "琴韵小筑");
	set("long", @LONG
但见疏疏落落四五座房舍，建造在一个不知是小岛还是半岛之上。房舍小巧
玲珑，颇为精雅。小舍匾额上写着“琴韵”两字，笔致颇为潇洒。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" :__DIR__"ru1",
		"down":__DIR__"huan_2",
]));
	set("objects",([
		__DIR__"npc/nantong":1,
		__DIR__"npc/nutong":1,
]));
	set("no_clean_up", 0);
	set("outdoors","room1");
	setup();
	replace_program(ROOM);
}
