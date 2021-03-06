// woodcutter.c
#include <ansi.h>
inherit NPC;
int do_heal();
void create()
{
	set_name("武者",({"wuzhe"}));
	set("gender", "男性" );
	set("age", 26);
	set("long","身怀绝技，一心只想闯荡江湖的青年人。\n");
	set("chat_chance", 15);
        set("chat_msg", ({
		(: do_heal :)
	}));
	set("combat_exp",5000);
	set("str", 30);
	set_skill("unarmed",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	setup();
	carry_object("/obj/cloth")->wear();
}
int do_heal()
{
	object me;
	me=query_leader();
	if(!me) return 1;
	if(query("kee")<query("max_kee")||query("eff_kee")<query("max_kee"))	 {
		say("武者从怀中掏出丹药吃了下去。\n");
		set("kee",query("max_kee"));
		set("eff_kee",query("max_kee"));
		say("武者气色立时变得好多了。\n");
		return 1;
	}
}
void init()
{
	add_action("do_zhao","zhao");
	add_action("do_kill","kill");
}
int do_kill(string name)
{
	object me;
	me=this_player();
	if(! name)	return 0;
	if(!query_leader())	return 0;
	if(me==query_leader())	{
		if(!present(name,environment()))	return 0;
		if(present(name,environment())==this_object())	{
		tell_object(me,"自已的手下也不放过？\n");
		return 1;
		}
		message_vision(CYN"武者大喝一声与"+me->query("name")+"共同向"+present(name,environment())->query("name")+"发起攻击！\n"NOR,me);
		command("kill "+name);
	return 0;
	}
	if(present(name,environment())==query_leader())	{
		message_vision(CYN"武者怒喝道：敢与我家主公过不去，找死！\n"NOR,me);
		command("kill "+me->query("id"));
	return 0;
	}
	return 0;
}
int do_zhao(string name)
{
	object me,npc;
	me=this_player();
	npc=present(name,environment());
	if(!npc)	{
		tell_object(me,"这里没这么个人。\n");
		return 1;
	}
	if(npc->query("zhao")==1)	{
		tell_object(me,"武者已归"+query_leader()->query("name")+"统领，你不能再招他了。\n");
		return 1;
	}
	if(me->query_temp("oldsix_flag/zhao"))	{
		tell_object(me,"你已经有随从了，不能再招啦！\n");
		return 1;
	}
	npc->set_leader(me);
	me->set_temp("oldsix_flag/zhao",1);
	message_vision("武者决定加入$N的行列。\n",me);
	npc->set("zhao",1);
	npc->set("title",me->query("name")+"的随从");
	return 1;
}
