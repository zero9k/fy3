// Room: /d/suzhou/beipingmen.c

inherit ROOM;

void create()
{
	set("short", "北平门");
	set("long", @LONG
厚厚青砖建起的城墙上爬满了青藤，也不知究竟有多少个年头了。守城的兵
勇不怀好意的瞪着你，在此徘徊显而易见不是什么好事，你加快了步伐。道路南
北延伸，南面是进城之路，西北方向依稀现出塔影。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" :__DIR__"chengbeijie4",
		"north" :__DIR__"qingshiru1",
]));
	set("objects",([
	__DIR__"npc/bingyong" :2,
]));
	set("no_clean_up", 0);
	set("outdoors","suzhou");
	setup();
	replace_program(ROOM);
}
