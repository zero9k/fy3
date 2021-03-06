// gun.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
}

void create()
{
	set_name("歪把机枪", ({ "ji qiang", "qiang", "gun" }) );
	set_weight(99999);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "挺");
		set("bullet", 100);
		set("value", 50000);
		set("material", "steel");
		set("long", "这是一挺进口的歪把机枪，装着一百发子弹。\n");
		set("wield_msg", "$N从背后卸下一把$n握在手中。\n");
		set("unequip_msg", "$N放下了手中的$n。\n");
	}
	init_blade(100);
	setup();
}

int do_aim(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("你把枪对准了自己.\n");

	if( this_object()->query("bullet") <=0)
		return notify_fail("子弹已经打光了。\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("浪费子弹啊？\n");

	if(obj == me)
		return notify_fail("想清楚了?!\n");

	message_vision(HIY 
"\n$N狞笑着将枪口对准了$n，打开了保险。\n\n" NOR, 
			me, obj);

	this_object()->set_temp("target", arg);

	return 1;
}

int do_shoot()
{
	object me, obj;
	string arg;

	me = this_player();

	if( !(arg = this_object()->query_temp("target")) ) 
		 {
                   this_object()->add("bullet", -10);
                   return notify_fail("你胡乱放了一阵枪。\n");
                 }

	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("你想浪费子弹啊？\n");

	message_vision(HIR "\n$N对准$n扣动了扳机！！！\n
        只听一声惨叫，$n满身血洞，倒在血泊里！\n\n" NOR,
			me, obj);

	this_object()->add("bullet", -10);
	obj->die();

	return 1;
}

