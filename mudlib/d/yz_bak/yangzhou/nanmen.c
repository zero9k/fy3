// Mr.music  yangzhou's 南门

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "南门");
        set("long", @LONG
	这儿就是扬州城的南门，因近来扬州城郊常有盗匪出没，不太安全，
所以一到晚上，城门就会关闭。

LONG
        );

        set("outdoors", "/d/yangzhou");
        set("objects", ([
        //      __DIR__"obj/box" : 1,
        ]));

        set("exits", ([
              "north" : __DIR__"yingshijie3",
              "south" : __DIR__"dukoulu",
                     ]));
        setup();
        replace_program(ROOM);
}

