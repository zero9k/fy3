// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;

void create()
{
        set_name("八宝弥勒佛像", ({ "xiang" }) );
        set_weight(500000);
        set_max_encumbrance(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("long", "身上缀满各类宝石,翡翠,黄金的弥勒佛像.\n");
                set("value", 50);
        }
}


