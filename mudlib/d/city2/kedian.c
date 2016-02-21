// Room: /d/city2/kedian.c

inherit ROOM;

void create()
{
	set("short", "京都客栈");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。据说全国各地
都有这样的分店，而且所有的客栈都归一个人所有。不过他从
来不露面，谁也不知道他究竟是怎样一个人。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"majiu",
  "west" : __DIR__"nandaj1",
]));
	set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/sufoer.c":1,
]));
	set("valid_startroom", 1);

	setup();
	replace_program(ROOM);
}
