//music  yangzhou's 打铁铺

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "打铁铺");
        set("long", @LONG
	这是一家打铁铺，铁匠们正抡着大锤，打造着各种铁器。
左侧货架上满是打好的家用铁器，右手货架上是常用的一些兵器，
象钢刀，短剑，匕首等。

LONG
        );

        set("objects", ([
                        __DIR__"npc/wangtiejiang" : 1,
                       ]));

        set("exits", ([
                        "east" : __DIR__"jiedao1",
                     ]));
        setup();
        replace_program(ROOM);
}

