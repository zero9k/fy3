// Room: /d/new/tianxia/1guan5
inherit ROOM;

void create()
{
  set ("short", "石板路");
  set ("long", @LONG
两边是高高的冬青树,即使在大雪飘飞的寒冬,依然青翠如昔.平整的石板
路打扫得干干净净,北面是片极大的广场.南面绿树掩映中,一片楼阁悠然挑起.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"binguan",
  "north" : __DIR__"1guan3",
]));
  set("outdoors", "/d/new");
  setup();
}
