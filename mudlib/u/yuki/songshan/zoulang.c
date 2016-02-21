// Room: /u/yuki/songshan/zoulang.c

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
    崇圣门左边的一条长廊，通向左冷禅的寝宫。走廊的路面是一尺
见方的大青石铺成，打扫的十分洁净。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/songshan/chongsheng.c",
  "west" : __DIR__"zoulang1",
]));

	setup();
	replace_program(ROOM);
}
