// Room: /d/xxy/upbath 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "浴室");
  set ("long", @LONG
一间蒸汽暧暧的浴室,房间密不透风,一只多半人高的浴桶下正烧着炭火.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"up1",
]));
  set("bath_room",1);
  setup();
}
