// thd:hill4.c

inherit ROOM;

void create()
{
      set("short", "盘龙岩");
	set("long", @LONG
路旁有块极大的岩石，其形若盘旋欲起之天龙，但又偏偏飞不起来。
次处就由次而得名，而此处向东不远有一山洞也因此被称作囚龙洞，作为
桃花岛囚人之所。
LONG
);

//	set("objects", ([ /* sizeof() == 1 */
//		__DIR__ "npc/chuanfu" :  1,
//	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "southdown" : __DIR__"hill3",  
          "east" : __DIR__"front_hole",
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

