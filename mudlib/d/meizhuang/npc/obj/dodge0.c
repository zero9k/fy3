// daodejing-ii.c

inherit ITEM;

void create()
{
	set_name("玄天步法上卷",({"bufa","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
	set("long","黄钟公所著的玄天步法上卷。\n");
	set("no_give",1);
		set("material", "paper");
	set("value",100);
	set("no_sell",1);
		set("skill", ([
	"name":"xuantian-bu",
	"exp_required":100,
	"max_skill":20,
	"sen_cost":10,
		]) );
	}
}
