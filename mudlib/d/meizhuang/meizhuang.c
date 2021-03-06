// Room: /d/suzhou/meizhuang/meizhuang.c

inherit ROOM;

void create()
{
	set("short", "梅庄");
	set("long", @LONG
你信步来到一座朱门白墙的大庄院外，行到近处见大门外写着“梅庄”
两个大字，旁边署着“虞允文题”四字，但觉这几个字儒雅之中透着勃勃
英气。
LONG
	);
	set("exits",([
	"south":__DIR__"xiaolu1",
	"north":__DIR__"qingshilu1",
]));
	set("objects",([
		__DIR__"npc/zhuangding":2,
]));
	set("no_clean_up", 0);
	set("outdoors","meizhuang");
	setup();
}

int valid_leave(object me,string dir)
{
	string fam;
	object npc;

	fam=(string)me->query("family/family_name");
	npc=present("zhuang ding",this_object());

	if( fam && fam!="孤山梅庄" && dir=="north" && objectp(npc))
	return notify_fail("庄丁喝道：闲杂人等禁入梅庄！\n");
	return ::valid_leave(me,dir);
}

