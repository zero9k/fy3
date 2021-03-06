// Room: /d/suzhou/meizhuang/shibanlu1.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条宽阔的石板路。道路两侧遍地梅树，透过梅树依稀是重峦叠障的
远山。微风习习煞是怡人，主人想必费了不少心思。南面是梅庄弟子的睡
房，北面则是澡堂。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"east":__DIR__"shibanlu3",
	"north":__DIR__"zaotangguodao",
	"south":__DIR__"shuifang",
	"west":__DIR__"shibanlu1",
]));
	set("no_clean_up", 0);
	set("outdoors", "meizhuang");

	setup();
	replace_program(ROOM);
}
