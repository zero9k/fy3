// Room: /d/suzhou/meizhuang/shibanlu1.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一条宽阔的石板路。道路两侧遍地梅树，透过梅树依稀是重峦叠障的
远山。微风习习煞是怡人，主人想必费了不少心思。再往东走是梅庄侧院
的尽头练功场，南面隐现刀光剑影，是梅庄的兵器库。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"south":__DIR__"bingqiku",
	"east":__DIR__"liangongchang",
	"west":__DIR__"shibanlu2",
]));
	set("no_clean_up", 0);
	set("outdoors", "meizhuang");

	setup();
	replace_program(ROOM);
}
