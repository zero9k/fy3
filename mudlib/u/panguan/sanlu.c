//make by temp
//ROOM: sanlu.c


inherit ROOM;

void create()
{
        set("short", "山间小路");
        set("long",@LONG
你走在一条山间崎岖的小路上，四周静悄悄的。西边有一大片的竹林，
东边是好像是个山谷。往北还有一条小路，似乎有一着凉亭掩映在密密的
树林中。
LONG
        );
        set("exits", ([
                "northup" : __DIR__"wangft",
                "southdown" : __DIR__"pmfsanjiao",
                   "eastdown" : __DIR__"pmgu",
                "westup" : __DIR__"zhudao1"
        ]));
        setup();
        replace_program(ROOM);
}
