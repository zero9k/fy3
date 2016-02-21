// Room: /d/xxy/up1 
inherit ROOM; 
 
void create ()
{
  set ("short", "天风楼二楼");
  set ("long", @LONG
四面的浅紫色缎面遮住了外面的寒风,雕花盘龙桌旁有几张檀木矮几,桌上
的水晶盘内盛满葡萄,香蕉等水果.一道红色楼梯通向下层.有几扇房门虚掩着.
LONG);

  set("objects", ([ /* sizeof() == 5 */
  "/d/obj/food/dishes/dish15.c" : 1,
  "/d/obj/food/dishes/dish11.c" : 1,
  "/d/obj/food/dishes/dish10.c" : 1,
  "/d/obj/food/dishes/dish03.c" : 1,
  "/d/obj/food/dishes/dish02.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "eastdown" : __DIR__"tianfeng",
  "north" : __DIR__"upsleep",
  "west" : __DIR__"upbath",
]));

  setup();
}
