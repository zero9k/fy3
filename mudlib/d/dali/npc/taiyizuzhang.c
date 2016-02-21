inherit KZZNPC;
#include <ansi.h>

string query_save_file() { return DATA_DIR + "npc/黑多隆"; }
void create()
{
#include <kzznpc.h>

	set("area_name","河西镇");
	set("area_file","/d/dali/hexi.c");
	set("ziyuan","鲜鱼");
	set("jizhi",70);
	set("kaifa",5);
	set("long","一个十分粗壮的大汉，听说曾在大理段府当过家丁。\n");

        setup();
carry_object("/obj/cloth")->wear();
carry_object("/obj/weapon/sword")->wield();
}

#include <die.h>