// Room: /d/new/tianxia/incave3
inherit ROOM;

void create()
{
  set ("short", "麒麟洞内");
  set ("long", @LONG
眼前黑黑的一片,看不清楚些什么,从黑暗深处传来野兽粗狂的吼叫.从
洞顶滴下的水掉在脸上,凉凉的.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"incave1",
]));
  setup();
}
