// Room: /d/kaifeng/road.c

inherit ROOM;

void create()
{
	set("short", "御街");
	set("long", @LONG
这条道横贯南北，北到宣德门，南至南盈门，是以前皇上出巡时
常走的道，所以修得是格外平整。道两边店铺不断。向南过去不远。
经过石拱门，就是相国寺，北面是朱雀门。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"gongmen",
  "north" : __DIR__"zhuque",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
