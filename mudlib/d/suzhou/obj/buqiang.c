#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("狙击步枪",({"zhuji buqiang","buqiang","qiang"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","把");
		set("material","iron");
		set("long","shoot [方向] <目标>，射程为02。\n");
	}
	setup();
}
void init()
{
	add_action("do_shoot","shoot");
}
int do_shoot(string str)
{
	object me,target,room;
	string dir,name;
	me=this_player();
	if(!str)
	return notify_fail("shoot [方向] <名字>\n");
	if(sscanf(str,"%s %s",dir,name)==2)  {
		if(!environment(me)->query("exits/"+dir))
		return notify_fail("没有这个方向！\n");
		if(!room=find_object(environment(me)->query("exits/"+dir)))
		room=load_object(environment(me)->query("exits/"+dir));
	}
	else	{
		name=str;
		room=environment(me);
	}
		target=present(name,room);
		if(!target)	return notify_fail("那儿没有这个目标！\n");
		if(!target->is_character())	return notify_fail("那不是个生物！\n");
		tell_room(environment(me),RED"“啪”的一声枪响，子弹朝着"+target->query("name")+"呼啸而去！\n"NOR);
		message_vision(RED"子弹呼啸而来，红光闪过之后$N倒在血泊之中！\n"NOR,target);
		target->die();
		return 1;
}
