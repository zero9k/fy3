//xiyuan1
  

inherit ROOM;

void create()
{
	set("short", "演出大厅");
	set("long", @LONG
这里就是大厅，台上正唱着戏呢，你可以坐下来叫上一壶茶，好好
的做一次票友。台上那位演员虽不是名角，唱起戏来倒也是有板有眼，
让人听了心情不竟一畅，偶然的不快顿时烟消云散。
LONG
	);
set("outdoors","/d/zhongzhou");

	set("exits", ([
		"east" : __DIR__"xiyuan",
		"west" : __DIR__"huazhuang",	
]));
	set("objects",([
		__DIR__"npc/guanzho":2,
	]));

	setup();
	replace_program(ROOM);
}

