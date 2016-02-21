inherit KZZNPC;
inherit F_VENDOR;

string query_save_file() {return DATA_DIR+"npc/吴四郎";}
void create()
{
#include <kzznpc.h>
set("chat_chance",5);
set("chat_msg",({
"吴四郎叫喊:草鞋,新打的草鞋,谁要买草鞋?\n",
"吴四郎喃喃自语:看来今天的草鞋又卖不出去了.\n",
(:random_move:),
}));
set("vendor_goods",([
"caoxie":__DIR__"obj/caoxie",
]));
	setup();
	carry_object("/obj/cloth")->wear();
	carry_object("/obj/std/armor/pijia")->wear();
	carry_object("/obj/std/weapon/wandao")->wield();
}
void init()
{
	::init();
add_action("do_vendor_list","list");
}


