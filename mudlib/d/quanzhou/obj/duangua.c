#include <armor.h>

inherit CLOTH;

void create()
{
       set_name("С�̹�", ({"duangua", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",
"Բ�ڶԽ�С���ӣ����˼�С���ӵĴ��ţ�\n");
                set("unit", "��");
                set("value", 500);
                set("material", "cloth");
                set("armor_prop/armor", 4);
             }
}
