// guozhendian.c �����


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
	�����Ǵ����Աߵ�һ����Ҳ�ǽӴ���Ҫ���˵ĵط������
ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ�������辰��ǽ���Ϲ�
��һЩ�ֻ���������������������һ���Ĳ��С����
LONG
	);

	set("exits", ([
		"south" : __DIR__"datang3",
		"west" : __DIR__"cetang",
		"north" : __DIR__"cundaota1",
	]));

	setup();
	replace_program(ROOM);
}