
// yinpiao.c

inherit MONEY;

void create()
{
	set_name("百两银票", ({"yin piao",  "cash","zhi bi","piao"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "cash");
		set("long", "一张面额一百两银子的银票。\n");
		set("unit", "叠");
		set("base_value", 10000);
		set("base_unit", "张");
		set("base_weight", 3);
	}
	set_amount(1);
}

