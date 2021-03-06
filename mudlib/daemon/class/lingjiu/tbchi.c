// /d/lingjiu/npc/tbhao.c 赤天部 裘婆婆
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;

string ask_me_1(string name);
string ask_me_2(string name);
void create()
{
	set_name("裘婆婆", ({ "qiu popo", "qiu", "popo" }));
	set("long",
	    "她是"+HIC"「灵鹫宫」"NOR+"九天九部中赤天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", HIC"赤天部首领"NOR);
	set("gender", "女性");
	set("age", 60);
        set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 23);
	set("class", "scholar");
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("kee", 1300);
	set("max_kee", 1300);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 2000);
	set("max_force", 2000);
	set("force_factor", 80);

	set("combat_exp", 700000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
        set_skill("sword",100);

	set_skill("liuyang-zhang",80);
	set_skill("yueying-wubu",80);
        set_skill("duzun-gong", 70);

	map_skill("force", "duzun-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
   	map_skill("sword", "tianyu-qijian");

        set("inquiry", ([
		"疗伤" : (: ask_me_1, "towel" :),
		"毛巾" : (: ask_me_1, "towel" :),
		"鹿皮酒袋" : (: ask_me_2, "lpjiudai" :),
		"白云熊胆丸" : (: ask_me_2, "baiyunwan" :),
        ]));
	set("yaopin_count_1", 5);
	set("yaopin_count_2", 1);

	create_family("灵鹫宫",4,"弟子");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "sword.san" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: command("unwield jian") :),
		(: command("wield jian") :),
            }) );
	setup();
carry_object("/obj/weapon/sword")->wield();
 	carry_object("/d/lingjiu/obj/qingyi")->wear();
        carry_object("/d/lingjiu/obj/doupeng")->wear();
        carry_object("/d/lingjiu/obj/jiudai");
        add_money("silver",25);
}
string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你怎麽又来要了？ 真是贪得无餍！";

	if (query("yaopin_count_1") < 1)
		return "抱歉，你来得不是时候。";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("yaopin_count_1", -1);

	message_vision("裘婆婆给$N一条" + ob->query("name") + "。\n", this_player());

	return "拿去吧。赶快到滦凤阁沐浴疗伤。";
}
string ask_me_2(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("yaopin_count_2") < 1)
		return "抱歉，你来得不是时候。";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("yaopin_count_2", -1);

	message_vision("裘婆婆给$N一颗" + ob->query("name") + "。\n", this_player());

	return "拿去吧。好好练功，保卫灵鹫宫。";
}
void init()
{
	object me, ob;
	mapping fam;

	::init();
	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& ((fam = ob->query("family")) && fam["family_name"] != "灵鹫宫" ))
	{
		if( !ob->query_temp("warned") ) {
		command("say 尊主有令：外人不得进入灵鹫宫，速速离开！");
			ob->set_temp("warned", 1);
	}
		else if( ob->query_temp("warned")<5 ) ob->add_temp("warned",1);
		else {
			command("say 大胆狂徒，竟敢擅闯灵鹫宫！！！\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}
}
