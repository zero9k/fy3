// Mr.music  yangzhou's 街道 4

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "街道");
        set("long", @LONG
	你走在扬州城北的一条小街上，因离城市中心较远，格外的清静优雅。
向南通往城区，向北是瘦西湖山庄。一路绿荫垂柳，鸟语花香，令人心旷神移。
不远处的一条碧绿的小湖就是闻名天下的瘦西湖了。

LONG
        );

        set("outdoors", "/d/yangzhou");
        set("objects", ([
        //      __DIR__"obj/box" : 1,
        ]));

        set("exits", ([
              "north" : __DIR__"shouxihu",
              "south" : __DIR__"yz-x1",
                     ]));
        setup();
        replace_program(ROOM);
}

