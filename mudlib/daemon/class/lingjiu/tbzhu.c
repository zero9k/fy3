// /d/lingjiu/npc/tbzhu.c 朱天部 石嫂
// By adx @ CuteRabbit 22:21 99-3-19

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("石嫂", ({ "shi sao", "shi", "sao" }));
	set("long",
	    "她是"+HIC"「灵鹫宫」"NOR+"九天九部中朱天部的首领.\n"+
	    "她跟随童姥多年, 出生入死,饱经风霜.\n");
	set("title", HIC"朱天部首领"NOR);
	set("gender", "女性");
	set("age", 30);
        set("shen_type",-1);
	set("attitude", "peaceful");

	set("per", 22);
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

        set("inquiry", ([
	"灵鹫宫" : "这里就是。\n",
	"童姥" : "她是灵鹫宫的主人。\n",
	"尊主" : "灵鹫宫现在的尊主是虚竹，他是灵鹫宫唯一的男子。\n",
	"生死符" : "你今年给本宫的贡金呢？\n",
        ]));


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
void init()
{
        object ob;
 
        ::init();
 
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
       if ((string)ob->query("family/family_name") == "灵鹫宫") 
	{
               message_vision("石嫂冲着$N点点头，微微笑了笑。\n",ob);
               return;
	}
	else	 message_vision("石嫂正瞪着$N，看的$N有些发毛。\n",ob);
}

int accept_object(object me, object ob)
{
	object qing;

        if( ob->query("money_id") ) 
	{
                if(ob->value() < 5)
		{
			command("heng");
			command("say 你打发叫化子啊！滚！");
			return 1;
		}
		else
		{
                        this_player()->apply_condition("shengsifu_poison", 0);
			command("say 好，你身上的生死符已解了！");
			command("say 下次给本宫的贡金一定要准时！");
			return 1;
		}
	}
}
