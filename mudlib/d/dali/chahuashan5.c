// Room: /d/dali/chahuashan5.c

inherit ROOM;

void create()
{
	set("short", "茶花山");
	set("long", @LONG
你走在茶花山上，这里遍地是生长茂盛的茶花。当然，大部
分是凡品，但偶尔也会有一两株佳品藏匿其中。西望不远是大理
城的北门，南边不远是城墙。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"chahuashan2",
  "eastdown" : __DIR__"chahuashan6",
]));
	set("outdoors", "dali");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/caichanu.c" : 1,
  __DIR__"obj/shanchahua" : 1,
]));

	setup();
	replace_program(ROOM);
}
