// Room: /d/quanzhou/chaoan.c

inherit ROOM;

void create()
{
	set("short", "草庵");
	set("long", @LONG
在莽莽森森的树林中,有一座草庵,庵靠山壁而建,庵内正壁天然石 
上,雕刻圆形佛图,牟尼佛身为白色,脸为辉绿石色,手部呈粉红色,天地 
灵气所钟,佛光氤氲. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/quanzhou");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bixiao-stone",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jushi.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
