// Room: /d/zhongzhou/wendingnan2.c

inherit ROOM;

void create()
{
	set("short", "文定南街");
	set("long", @LONG
这是中州城文定南街，宽敞的街道看的人不竟心情一畅。街对面好象
有一家茶楼。可进出的人你看着总觉得有点不对劲。
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiashi" : 1,
  __DIR__"npc/qiying" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"maodun",
  "north" : __DIR__"wendingnan1",
  "west" : __DIR__"chalou",
  "south" : __DIR__"wendingnan3",
]));
	set("outdoors", "/u/wen");

	setup();
	replace_program(ROOM);
}
