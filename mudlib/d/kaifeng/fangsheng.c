// Room: /d/kaifeng/fangsheng.c

inherit ROOM;

void create()
{
	set("short", "放生池");
	set("long", @LONG
从三尺台阶走下就是大街了。台阶旁挖了一个小池子，边上用白石
围起了栏杆。北边的池壁上『放生池』几个字涂成了红色。由于池的
一边靠近街道，方便别人作出善举，但整天见人把鱼鳖放下去，总不
见影，多是附近的泼皮无赖晚上摸来作宵夜了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"qianshou",
  "westdown" : __DIR__"wroad",
]));
	set("outdoors", "/d/kaifeng");

	setup();
	replace_program(ROOM);
}
