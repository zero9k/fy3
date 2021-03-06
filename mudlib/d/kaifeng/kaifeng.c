// Room: /d/kaifeng/kaifeng.c

inherit ROOM;

void create()
{
	set("short", "开封府");
	set("long", @LONG
开封府统管开封这片区域。现任的开封府尹包拯包大人铁面无私。
明断秋毫，深得民众信任，被称为包青天。大门一边一个高大的鼓架
告状鸣冤的可以在此敲鼓。
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhaohu.c" : 1,
  __DIR__"npc/zhanglong.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jiedao1",
  "west" : __DIR__"datang",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
