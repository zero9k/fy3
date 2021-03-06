// Room: /d/hangzhou/pinghu.c

inherit ROOM;

void create()
{
	set("short", "平湖秋月");
	set("long", @LONG
"万顷寒光一夕铺，水轮行处片云无，鹫峰遥度西风冷，桂子纷纷点 
玉壶",眼前水波浩淼,水平如镜,秋高气爽之时,湖面平静如镜，皓洁的秋 
月当空，月光与湖水交相辉映，颇有“一色湖光万顷秋”之感.路边有座 
小亭子,名为'望湖亭'. 
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"wanghu.c",
  "east" : __DIR__"baidi3.c",
]));
	set("no_clean_up", 0);
	set("outdoors", "/d/hangzhou");

	setup();
	replace_program(ROOM);
}
