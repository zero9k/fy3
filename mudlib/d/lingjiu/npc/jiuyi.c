// NPC jiuyi.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("九翼道人", ({ "jiuyi daoren", "jiuyi"}));
	set("long",
	    "他是西夏一品堂礼聘的高手,身材高瘦,脸上总是阴沉沉的,\n"+
	    "他轻功极高,擅使雷公挡,凭一手雷公挡功夫,成为江湖的一流高手.\n");
	set("title", "西夏一品堂高手");
	set("gender", "男性");
	set("nickname", HIR "雷动于九天之上" NOR);
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);

	
	set("max_kee", 1000);
 	set("kee", 1000);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 10);

	set("combat_exp", 1000000);
	set("score", 100000);
	setup();
}