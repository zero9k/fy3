// yangzhou ���ϰ� 

inherit NPC;
//inherit F_VENDOR;
//inherit F_DEALER;

void create()
{
	set_name("��²�", ({ "li dechang", "li","deng chang","boss" }));
	set("title", "�׵��ϰ�");
	set("mingwang", 10);

	set("gender", "����");
	set("age", 45);
	set("long",
		"���ϰ������������������ˣ����˼�ʮ����׵����⡣\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
//	set("vendor_goods", ({
//		__DIR__"obj/mabudai",
//		__DIR__"obj/changjian",
//	}));
	
	setup();
}

//void init()
//{
        //add_action("do_list", "list");
        //add_action("do_buy", "buy");
//}