// Room: bianj008.c
// mike.99.3.1
inherit ROOM;

void create()
{
	set("short", "开宝寺大殿");
	set("long",@LONG
这里是汴京开宝寺大殿，殿正中供奉一尊五米余高的接引
佛铜像 ... ...
LONG
);
       set("exits", ([ /* sizeof() == 1 */
            "south"  : __DIR__"bianj007",
       ]));
	setup();
       replace_program(ROOM);
}
