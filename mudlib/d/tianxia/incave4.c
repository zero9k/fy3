// Room: /d/new/tianxia/incave4
inherit ROOM;

void create()
{
  set ("short", "麒麟洞内");
  set ("long", @LONG
两边山壁覆满各类不知名的蕨类植物.一线天光从头顶不规则地射下
来,扭曲入蛇.地上湿潞潞的,不知哪来的水.南边有道台阶一直向下,北
面的一道石梁横过了地下河.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"incave5",
  "north" : __DIR__"bridge1",
]));
  setup();
}
