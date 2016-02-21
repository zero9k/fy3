// Room: /d/huanggon/tongyaopu.c

inherit ROOM;

void create()
{
	set("short", "回春堂药铺");
	set("long", @LONG
回春堂药铺在京城很有名气,听说此地的药材还御供.你一进来就闻
到一股浓浓的药味,那是从药柜上的几百个小抽屉里散发出来的,西面是
间内室,用布帘遮挡着.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yenongyi.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"neishi1",
  "east" : __DIR__"xidan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
