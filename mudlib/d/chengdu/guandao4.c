//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
��·���Կ����˽��ɫ���Ͳ˻�,΢�紵��,Ʈ��������,����
����,�ۿ������������츮֮��---�ɶ���Ҫ���ˡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"shanlu5",
                "west" : __DIR__"guandao3",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

