// Mr.music  yangzhou's 东关街 1

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "东关街");
        set("long", @LONG
	你走在扬州城最繁华的大街上，沿街店铺林立，商贾成群。白天
这里车马如龙，人声鼎沸，夜里是星光伴月，灯火通明。这里是城中的主
要的商业和文化娱乐街，素有“春风十里扬州路”的美称。向北是城里有
名的姚记钱庄。南边就是扬州府衙了。

LONG
        );

        set("outdoors", "/d/yangzhou");

        set("objects", ([
                   __DIR__"npc/shusheng" : 1,
                   __DIR__"npc/xiaohaizi" : 1 ,
                 ]));

        set("exits", ([
              "west" : __DIR__"yz-x2",
              "east" : __DIR__"dongguan2",
              "north": __DIR__"yaoji",
              "south": __DIR__"yamen",
                     ]));
 //       create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
        setup();
        replace_program(ROOM);
}

