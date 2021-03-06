// Room: /d/suzhou/chengnanjie3.c

inherit ROOM;

void create()
{
	set("short", "城南街");
	set("long", @LONG
南面隐约望见高高的城墙，想必是盘门了。西边是座高大的宅院，你向路人
打听了一下，原来新近开出的防具店。你四处张望了一下，东边依稀可见两座塔
影，夕阳照耀之下更显得一股苍桑之气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" :__DIR__"chengnanjie2",
		"south" :__DIR__"chengnanjie4",
		"east" :__DIR__"shuangta",
		"west" :__DIR__"liangongtang",
]));
	set("outdoors","suzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
