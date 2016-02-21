// Room: /d/quanzhou/qianzhuang.c

inherit ROOM;

void create()
{
	set("short", "姚记钱庄");
	set("long", @LONG
姚记钱庄在全国都有分号,此处是泉州分号,店堂中有一长柜台.姚
老板亲自坐柜台,虽然他的钱早已数不清了.
LONG
	);
	set("no_clean_up", 0);
set("no_fight",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wstreet1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yaolaoban.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
