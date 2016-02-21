#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("虚气丸",({"xuqi wan","wan"}));
	set("unit","粒");
	set("value",100);
	set("long","可以恢复少量气的药丸。\n");
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();
      if( living(this_player()) ==0 ) return 0;
   if(!id(arg))
       return notify_fail("你要吃什么？\n");
if ((int)time()-me->query("oldsix_flag/eat_yao")<60)
return notify_fail("你刚吃过补药,连续吃身体受不了.\n");
	me->receive_curing("kee",10);
	me->receive_heal("kee",10);
me->set("oldsix_flag/eat_yao",time());
	message_vision("$N吃下一粒虚气丸，气血似乎有所恢复。\n",me);
	destruct(this_object());
	return 1;

}
