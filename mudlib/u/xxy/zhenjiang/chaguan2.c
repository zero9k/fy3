//musix zhenjiang 's 春来茶馆二楼
inherit ROOM;

void create()
{
	set("short", "春来茶馆二楼");
	set("long", @LONG
	这里是春来茶馆的二楼客房，供五湖四海的来客们休息休息。

LONG
	);

	set_light(0);
	set("sleep_room", 1);
	set("no_fight", "1");
        set("hotel",1);

	set("exits", ([
		"down" : __DIR__"chaguan",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "down" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

