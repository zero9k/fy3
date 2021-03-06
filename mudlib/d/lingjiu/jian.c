// Room: /d/lingjiu/jian.c

inherit ROOM;

void create()
{
	set("short", "百丈涧");
	set("long", @LONG
山道到此突然消失，在你面前是一条山涧，山涧之中云雾缭绕，你根
本无法看清对面。一条铁索(tiesuo)深入云中，旁边有一块石碑(bei)。
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 2 */
  "tiesuo" : "这是通往对面的“接天桥”，你也许可以走过(zou)去。
",
  "bei" : "『灵鹫宫』重地，擅入者死！
",
]));
	set("objects", ([ /* sizeof() == 2 */
  "/daemon/class/lingjiu/tbhao.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"yan",
	"northup":__DIR__"xianchou",
]));
	set("outdoors", "lingjiu");

	setup();
}

int valid_leave(object me,string dir)
{
	string family;
	object ob;

	family=(string)me->query("family/family_name");
	ob=present("yu popo",this_object());

	if(family && family!="灵鹫宫" && objectp(ob)&& dir=="northup")
	return notify_fail("余婆婆怒道：闲人莫入！\n");

	return ::valid_leave(me,dir);
}

