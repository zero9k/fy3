// daodejing-ii.c

inherit ITEM;

void create()
{
	 set_name("�������ַ���ƪ",({"shoufa","book","shu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	set("long","�ڰ���Ǳ��ר�еİ����ַ�ָ�ϡ�\n");
	set("no_give",1);
		set("material", "paper");
	set("value",100);
	set("no_sell",1);
		set("skill", ([
	"name":"mantianxing",
	"exp_required":10000,
	"max_skill":60,
	"sen_cost":30,
		]) );
	}
}