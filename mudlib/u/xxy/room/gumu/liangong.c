// liangong.c 练功室
// By Lgg,1998.9

inherit ROOM;

void create()
{
	set("short", "练功室");
	set("long", @LONG
	这座石室形状甚是奇特，前窄後宽，成为梯形，东边半圆，西边
却作三角形状，原来这是以前重阳祖师的练功室，前窄练掌，後宽使拳，
东圆研剑，西角发镖。
LONG
	);

	set("exits", ([
		"east" : __DIR__"zhengting",
		"north" : __DIR__"xiuxishi",
	]));

	setup();
	replace_program(ROOM);
}