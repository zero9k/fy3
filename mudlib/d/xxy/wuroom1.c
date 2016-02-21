// Room: /d/xxy/wuroom1.c

inherit ROOM;

void create ()
{
  set ("short", "武字二号楼");
  set ("long", @LONG
登上几级楼梯,你走上二楼,这里的一切显得十分富丽堂皇,从红漆栏杆
向外眺望,满园春色入目,在北面是武士休息的地方.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wushou.c" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wuroom4",
  "eastdown" : __DIR__"zoulang6",
]));
  set("outdoors", "/d/xxy");

  setup();
}
int valid_leave(object me,string dir)
{
   object ob;
   string str;
       ob=present("pai",me);
        if (dir=="north")
              {
                 if (!ob) return notify_fail("你溜了进来，还想到处遛么?\n");
                   str=ob->query("name");
                 if (str=="铁牌"||str=="铜牌")
                        return notify_fail("你的等级不够进入武字楼!\n");
               }
    return ::valid_leave(me,dir);
}
     