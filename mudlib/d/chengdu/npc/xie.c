inherit KZZNPC;

string query_save_file() { return DATA_DIR + "npc/谢长风"; }
void create()
{
#include <kzznpc.h>

	set("area_name","成都珠宝店");
	set("area_file","/d/chengdu/workroom.c");
	set("long", "他实际上只有四十来岁，岁月的流逝和生活的磨难使他看\n"+
"起来已有六十多了。每当他完成一件精美的作品的最后一\n"+
"笔时，浑浊的眼眸就会闪出一丝亮光，一双巧手稳如磬石。\n");
set("inquiry", ([
"海洋之心" : "它是我先祖传下来的手艺，唉，不知道会不会从我这里失传啊。\n",
]));
	set("age",40);
	setup();
	carry_object("/obj/cloth")->wear();
}



