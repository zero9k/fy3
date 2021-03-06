// Room: /d/huanggon/qianqingon.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "乾清宫");
	set("long", @LONG
乾清宫分前后两部分,前殿是皇上日场处理政务之所.三级御阶之上
是皇上的龙桌龙椅,台阶之间高脚琉璃灯大放光明,龙椅两侧瑞鹤翔云,
后面是九龙屏风,之上是正大光明的匾额.龙座边高挂黄榜(huang bang).
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"jiaotaidian",
  "west" : __DIR__"yangxindian",
  "south" : __DIR__"qianqinmen",
]));
set("no_clean_up", 1);
set("no_steal",1);
set("no_fight",1);
	set("objects", ([ /* sizeof() == 2 */
__DIR__"npc/zhishi.c" : 1,
  __DIR__"npc/kangxi.c" : 1,
]));
	setup();
}
void init()
{
   add_action("do_look","look");
  }
int do_look(string arg)
{
   mapping *quest,who;
   string name,id,str=YEL"黄榜\n"NOR;
   string *whtodo;
   int i;
   if (arg!="huang bang") return 0;
   quest=query("huangbang");
   if (!quest) {
   	write("这是张空白的金丝巧绣黄榜.\n");
   	return 1;
        }
   if (query("item_desc")) return 0;
   whtodo=query("what");
   for (i=0;i<9;i++)  {
   	who=quest[i];
   	name=i+1+".向"+who["name"];
   	id="("+who["id"]+")"+"询问";
   	str+="        "+name+id+HIR+whtodo[i]+NOR+".\n";
   }
  set("item_desc",([
  "huang bang":str,]));
  write(str);
  return 1;
}
