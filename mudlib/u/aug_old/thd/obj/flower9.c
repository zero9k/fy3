// flower9.c

inherit ITEM;

void create()
{
	set_name("灵脂兰", ({ "lingzhi lan" }) );
	set_weight(10);
	if( !clonep() ) {
		set("unit", "朵");
		set("value", 0);
		set("long", 
"这是朵极为罕见的兰花，是黄岛主花重金卖来的。美丽异常，但有剧毒。\n");
	}
	setup();
}
