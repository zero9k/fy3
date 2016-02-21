// Room: /d/huanggon/zhaomuchu.c

inherit ROOM;

void create()
{
	set("short", "太监招募处");
	set("long", @LONG
一间大宅子,黑色的大板门上贴了张红纸条,上写'太监招募处',原
来这是宫中招太监的处所,有吃不饱活不下去的,都可来此报名.北面是
东长安街.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoguizi.c" : 1,
  __DIR__"npc/haidafu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"echangan",
]));

	setup();
	replace_program(ROOM);
}
