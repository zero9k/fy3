//Mr.music yangzhou 短剑

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("竹剑",({"zhujian","zhu jian","jian","sword"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","竹子削成的短剑，杀伤力很小。\n");
	set("value",100);
	set("material","bamboo");
	}
	init_sword(5);

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");

	setup();
}
