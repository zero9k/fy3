// Room: /d/quanzhou/daxiong.c

inherit ROOM;

void create()
{
	set("short", "大雄宝殿");
	set("long", @LONG
一眼看进去,只见殿中都是密密麻麻的柱子,仔细数一下的话,就会发 
现共有96根,所以又称百柱殿,殿中供奉着五方佛神像,殿顶斗拱雕刻飞天 
乐伎24路,就连殿前月台青石基座都雕刻了浮雕,十分精美. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"obj/yougang.c" : 1,
  __DIR__"npc/fangzhang.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wstreet3",
  "westup" : __DIR__"jietai",
]));

	setup();
	replace_program(ROOM);
}
