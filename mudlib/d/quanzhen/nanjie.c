// nanjie.c 南街


inherit ROOM;

void create()
{
	set("short", "南街");
	set("long", @LONG
	这里是长安的南街，说是街，不过是一条小胡同而已。路上一个人
也没有。街的尽头有一扇小门。从这里往北，就是长安镇的中心了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhongxin",
		"southeast" : __DIR__"fu-cemen",
	]));

	setup();
set("outdoors","/d/quanzhen");
	replace_program(ROOM);
}
