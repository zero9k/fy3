// Room: /u/swordman/yangzhou/chanfang
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "禅房");
  set ("long", @LONG
这里是一间简陋的禅房，只有地上一张草席。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"damingshi1",
]));
        create_door("south", "小门", "north", DOOR_CLOSED);
  set("no_magic", 1);
  set("no_fight", 1);

  setup();
}
