// flower1.c

inherit ITEM;

void create()
{
	set_name("金带菊", ({ "juhua" }) );
	set_weight(10);
	if( !clonep() ) {
		set("unit", "朵");
		set("value", 0);
		set("long", 
"这是朵美丽的菊花，花瓣上还带着一条条的金黄的的条纹。\n");
	}
	setup();
}
