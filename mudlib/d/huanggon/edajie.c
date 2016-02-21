// Room: /d/huanggon/edajie.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是条东西向的街道,向西穿过天安门广场.街道两边招牌林立,吆喝
声不断,因为是京城,治安很好,所以生意人挺多.来往的人中大多手提着鸟
笼,这是八旗子弟,有俸禄的人家.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/huanggon");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jiaoqiying",
  "west" : __DIR__"guangchang",
  "east" : __DIR__"edajie1",
]));

	setup();
	replace_program(ROOM);
}
