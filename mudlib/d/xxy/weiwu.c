// Room: /d/xxy/yangwu 
inherit ROOM; 
 
void create ()
{
  set ("short", "威级考场");
  set ("long", @LONG
这是威级考场,凡比武胜过考官者,可得铜牌一块,凭此可进威级宿处. 
房间中空空荡荡,便于施展手脚.比武之中,若有死伤,各按天命. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/train2.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yongdao",
]));

  setup();
}
