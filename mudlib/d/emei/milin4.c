// Room: /u/xxy/room/milin4
inherit ROOM;

void create()
{
  set ("short", "密林");
  set ("long", @LONG
这是一片浓密的杉木林,枝柯交茅,绿云蔽日,据说,以前有个和尚名
叫寂完的,以'大乘经'字数为准,率领门徒广植树木,总有10.9万余株,不
过对你来说不是好事,因为你已迷路了.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"fohushi",
  "west" : __DIR__"milin2",
  "east" : __DIR__"milin2",
  "south" : __DIR__"milin3",
]));
set("outdoors","/d/emei");
  setup();
  replace_program(ROOM);

}
