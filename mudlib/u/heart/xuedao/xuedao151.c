//This xuedao151 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "青石屋");
  set("long",@LONG
master所在。
LONG
  );
  set("exits", ([ /* sizeof() == 2 */ 
      "out" : __DIR__"xuedao153",
      "north" : __DIR__"xuedao152",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/2");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
