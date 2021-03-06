// Room: /d/emei/jiulaofe.c

inherit ROOM;

void create()
{
	set("short", "九老峰");
	set("long", @LONG
地势至此豁然开阔,整个峰头种满了百年的古松,上与白云相应,下
有松涛阵阵,树下掉满了松子,混和着青草的清香,崖边的一棵松树枝叶
葱茏,树下的一块大石旁正有两位老人在悠闲手谈.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kong.c" : 1,
]));
	set("outdoors", "/d/emei");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"dongwai",
  "east" : __DIR__"yixiant.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
