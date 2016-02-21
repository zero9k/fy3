// thd:dukou_jx.c

inherit ROOM;

void go_back();

void create()
{
      set("short", "码头");
	set("long", @LONG
这是个很小的码头。港中停的也大多是渔船，都是破破烂烂的，其中
只有一艘船看来虽小，但很精制。看那设计，看那用料，肯定出自能人之
手。据渔民传说东海有岛名桃花，这艘船说不得就和桃花岛有关。现在码
头上没什么人，只有一个哑巴在闲逛。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/chuanfu2" :  1,
	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"bulletin" : "...\n",
//    ]));

      set("exits", ([ /* sizeof() == 1 */
		"west" : "/d/jiaxing/luwei"
	]));
      
	set("outdoors", "thd");

	setup();
	replace_program(ROOM);
}

