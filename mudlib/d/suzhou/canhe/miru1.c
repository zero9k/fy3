// Room: /d/suzhou/canhe/miru1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
密道内阴暗异常，好在墙壁上油灯微弱的光线能让你分辨出大概的方向。密
道内除了水滴声，就剩自己的脚步声了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southdown" :__DIR__"miru2",
		"up" :__DIR__"houting",
]));
	set("objects",([
		__DIR__"npc/shashou":1,
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me,string dir)
{
	if(dir=="up"&&me->query("id")=="sha shou")  {
	tell_room("/d/suzhou/canhe/houting",RED"密道内传来杀手的阵阵吼声！\n"NOR);
	return 0;
	}
	return 1;
}
