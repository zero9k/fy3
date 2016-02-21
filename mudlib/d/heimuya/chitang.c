//room: 
inherit ROOM;

void create()
{
  set("short","池塘");
  set("long",@LONG
这是个小池塘，塘边绿柳轻拂，花团锦缀。塘中鸳鸯双双对对，一边几
头丹顶鹤使此地平添几分仙气，西面就是圣姑的居处。东边是厨房，北面就
是白虎堂了，可要小心。
LONG );

  set("exits",([
      "north" : __DIR__"baihutang",
      "west"  : __DIR__"shenggu",
      "east"  :__DIR__"chufang2",
  ]));
  set("objects",([
      "/d/dali/npc/xianhe" : 4,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}

