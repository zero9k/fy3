//zhenwu jian   from nangong
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name("真武剑", ({ "zhenwu jian", "zhenwu","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
		set("value",100000);
        	set("material", "iron");
        	set("long", "这是武当名剑传说是真武大帝传下来的\n");
        	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n");
	}
	init_sword(100);
	setup();
}
