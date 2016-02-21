inherit NPC;

void create()
{
	int skill;

	set_name("敲钟老人", ({ "oldman", "laoren","qiaozhong"}) );
	set("gender", "男性" );
	set("age", 60+random(30));
	set("long", "躬背曲腰的老人,脸上皱纹写出了一生的沧桑。\n");

	set("combat_exp",1000+random(3000));
       set_skill("parry",20+random(20));
	set_skill("dodge", 20+random(20));
	set_skill("unarmed", 20+random(20));
	setup();
	carry_object("/obj/cloth")->wear();
            add_money("silver",2);
}
void init()
{
	object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("meeting");
                call_out("meeting", 1, ob);
        }
}
void meeting(object ob)
{ switch(random(3))
  {   case 1:
        command("say 看来我这身子骨,是没多长日子好活了!\n");
        break;
      case 2:
        message_vision("$N一边握起拳头捶着腰,边使劲敲响大钟!\n",this_object());
        break;
      case 3:
       command("smile");
        break;
    }
}