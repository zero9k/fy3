//Mr.music yangzhou 长剑

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("泥刀",({"nidao","blade"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","是把木制泥刀，攻击力不强，似乎是个古董。\n上面密密麻麻的不知写了些什么。\n");
		set("value",50000);
		set("material","wood");
		set("skill",([
							"name" :"blade",
                                "exp_required":0,
                                "sen_cost":20,
                                "difficulty" :20,
                                "max_skill":30,
		]));
	}
	init_blade(2);

// These properties are optional, if you don't set them, it will use the
// default values.


		set("wield_msg", "$N抽出一把黝黑的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	setup();
}
