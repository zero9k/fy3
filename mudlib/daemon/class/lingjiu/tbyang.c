// /d/lingjiu/npc/tbyang.c 阳天部 符敏仪
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;
string ask_me(string name);
void create()
{
	set_name("符敏仪", ({ "fu mingyi", "fu"}));
	set("long",
	    "她是"+HIC"「灵鹫宫」"NOR+"九天九部中阳天部的首领.\n"+
	    "她号称「针神」.\n");
	set("title", HIC"阳天部首领"NOR);
	set("gender", "女性");
	set("nickname", HIG "针神" NOR);
	set("age", 20);
        set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 21);
	set("class", "scholar");
	set("str", 25);
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

	set_skill("liuyang-zhang",80);
	set_skill("yueying-wubu",80);
	set_skill("duzun-gong", 70);
        set_skill("tianyu-qijian", 70);

	map_skill("force", "duzun-gong");
        map_skill("dodge", "yueying-wubu");
	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword","tianyu-qijian");

        set("inquiry", ([
		"护腕" : (: ask_me, "huwan" :),
		"护腰" : (: ask_me, "huyao" :),
		"手套" : (: ask_me, "shoutao" :),
		"指套" : (: ask_me, "zhitao" :),
		"皮靴"   : (: ask_me, "pixue" :),
		"防具" : "你需要什么防具呢？\n",
        ]));
	set("huju_count", 1);


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
string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "灵鹫宫")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有这样防具吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("huju_count") < 1)
		return "抱歉，你来得不是时候，防具已经发完了。";

	ob = new("/d/lingjiu/obj/" + name);
	ob->move(this_player());

	add("huju_count", -1);

	message_vision("符敏仪给$N一件" + ob->query("name") + "。\n", this_player());

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
