//musix yangzhou's 禅房

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
	这里是一间简陋的禅房，只有地上一张草席。

LONG
	);

	set("sleep_room", 1);
	set("no_fight", "1");
//        set("hotel",1);

	set("exits", ([
		"south" : __DIR__"daxiongbaodian",
	]));

	setup();
}


