// Room: /d/zhongzhou/dukou.c

inherit ROOM;

void create()
{
	set("short", "渡口");
	set("long", @LONG
这里是通往去扬州城的渡口，前面就是滚滚长江，向南就是中州府。
江边停着些[33m小船[37m。不远处一座大桥，斜斜的拉于江面上。
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("no_sleep_room", 1);
	set("item_desc", ([ /* sizeof() == 2 */
  "chuan" : "这些小船也许可以上。
",
  "船" : "这是些小船，好象没人管理，也许可以自己划.
",
]));
	set("outdoors", "zhongzhou");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shusheng" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"daqiao",
  "south" : __DIR__"dukoulu",
]));

	setup();
	replace_program(ROOM);
}
