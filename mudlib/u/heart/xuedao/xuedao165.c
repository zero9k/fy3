//This xuedao165 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "峭壁");
  set("long",@LONG
这是一间空空荡荡的房间。
LONG
  );
  set("exits", ([ /* sizeof() == 2 */ 
      "westdown" : __DIR__"xuedao164",
      "climb" : __DIR__"xuedao166",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/1");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
