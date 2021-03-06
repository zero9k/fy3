// Room: /d/quanzhou/gulou.c

inherit ROOM;

void create()
{
	set("short", "钟楼");
	set("long", @LONG
钟楼是一座高五丈左右的亭间,上面挂了一口大钟,用绳索拉动悬挂 
在钟下的谠而鸣,已经有些年头了. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhendian",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/literatebook.c" : 1,
  __DIR__"npc/qiaozhong.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
