//Oldsix's 钢剑

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("钢剑",({"gangjian","gang jian","jian","sword"}));
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long", "这是一把精钢打造的长剑，杀伤力较强。\n");
	set("value",5000);
	set("material","steel");
	}
	init_sword(30);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

// The setup() is required.

	setup();
}
