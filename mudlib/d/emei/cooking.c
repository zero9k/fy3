// Room: /d/emei/cooking.c

inherit ROOM;

void create()
{
	set("short", "膳室");
	set("long", @LONG
这里是用餐的地方。九老久不食人间烟火,这里的东西主要是为弟子
们准备的，一张石桌上摆着桃子、馒头、包子、黄精之类的食物，你要
是饿了，可以自己拿着吃。屋角摆着口大水缸，你可以从中舀水来喝.
LONG
	);
	set("objects", ([ /* sizeof() == 5 */
  __DIR__"npc/wenqing.c" : 1,
  __DIR__"obj/huang.c" : 2,
  __DIR__"obj/pot.c" : 1,
  __DIR__"obj/baozi.c" : 3,
  __DIR__"obj/taozi.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"qiandong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
