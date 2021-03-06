// Mr.music  yangzhou' 唐伯虎

inherit NPC;

void create()
{
	set_name("唐伯虎", ({ "tangbohu","tang", "hu" }));
	set("long", "赫赫有名，风流倜傥的江南才子。\n");
	set("gender", "男性");
	set("age", 35);
        set("per",60);
        set("mingwang",1);
	set_skill("literate", 200);

        set("title","江南第一才子");
	set_skill("unarmed", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 90);
	set_temp("apply/damage", 50);

	set("combat_exp", 900000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 1);
	set("chat_msg", ({
	       	"唐伯虎摇了摇手中的扇子，说道：多学点文化吧，不会白学的。\n",
                " “想当年...” ,唐伯虎说着似笑非笑的看了秋香一眼，很陶醉的样子。\n",
                	}) );
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/唐"))
		return 0; 
	ob->add_temp("mark/唐", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/唐"))
		who->set_temp("mark/唐", 0);
	if (ob->query("money_id") && ob->value() >= 500) {
		message_vision("唐伯虎微微一笑，向$N点了点头。\n", who);
		who->add_temp("mark/唐", ob->value() / 30);
		return 1;
	}
	return 0;
}
