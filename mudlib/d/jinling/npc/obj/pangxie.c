
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name(HIC"清蒸螃蟹"NOR, ({"pangxie", "xie"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一只蒸熟的长江螃蟹。\n");
                set("unit", "只");
                set("value", 500);
                set("food_remaining", 4);
                set("food_supply", 40);
        }
}
