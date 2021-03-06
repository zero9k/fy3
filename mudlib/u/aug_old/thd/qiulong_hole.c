// thd:qiulong_hole.c
// 97.7.14 by Aug

inherit ROOM;

void create()
{
      set("short", "囚龙洞");
	set("long", @LONG
这里就是囚龙洞。这个山洞并不大，但确很干燥，也很干净，适合人
的居住。洞顶还有不少小洞，阳光从洞顶洒下了，把一切照的通明。这里
虽然是桃花岛囚人之所，但确没有一般监狱的阴森恐怖，因为能被黄岛主
囚禁的也不是一般人。也正因为如此，这里名为囚龙洞。
LONG
);

	set("objects", ([ /* sizeof() == 1 */
		__DIR__ "npc/zhou_botong" :  1,
	]));

//	set("detail", ([ /* sizeof() == 1 */
//		"duilian" : "桃花影弱飞神剑，碧海潮生按玉箫。\n",
//    ]));

      set("exits", ([ /* sizeof() == 2 */
          "east" : __DIR__"back_hole",
          "west" : __DIR__"front_hole",
	]));
      
	setup();
//	replace_program(ROOM);
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) ) 
	{
		remove_call_out("setup_obj");
		call_out("setup_obj", 1, ob);
	}
}

void setup_obj(object ob)
{
	if(present("jiuyin jing1", ob))
	{
		("/cmds/std/kill")->main(this_object(), ob->name());
	}
}

int valid_leave(object me, string dir)
{
  object ob;

  if(dir!="east") return ::valid_leave(me, dir);

  ob = present("zhou", this_object());
  if( objectp(ob) && ob->is_npc() )
    return notify_fail("周伯通双手一拦，不让你进去，说道：这又不是你家，不要乱走嗷！\n");
  else
    return ::valid_leave(me, dir);
}
