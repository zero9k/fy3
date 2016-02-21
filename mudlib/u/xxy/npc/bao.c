// guard.c

#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
	set_name("包拯",({"bao zheng","bao"}));

	set("title","龙图青天");
	set("gender", "男性" );
	set("age",40);
	set("str",50);
	set("cor",30);
	set("cps",50);
	set("int",50);
	set("con",50);
	set("mingwang",50000);
	set("long",
	"面色黝黑，相貌清奇，气度不凡。让你不由自主，好生敬仰.
你有什么信息要通告天下的,可以付5两金子.天下各城门都会出告示.\n"
	);
	set("attitude","friendly");
	set("inquiry", ([
	]) );
	setup();
}
void init()
{
  ::init();
  add_action("do_post","tonggao");
}
int accept_object(object who,object item)
{	
	if(item->query("money_id") &&
	item->value()>=50000)
	{
		command("say 钱我就收下了,请用通告(tongao xxx)说明你的要求。");
	who->set_temp("bao_flag",1);
		return 1;
	}
	command("ask "+who->query("id")+" about 至少5两金子！");
	return 0;
}
void done_post(object me, mapping note, string text)
{
        note["msg"] = text;
        set("note", note);
 command("say 你的通告已经颁布天下,你可以走了.\n");        
        this_player()->set_temp("post_ok_la",1);
        save();
        return;
}
int do_post(string arg)
{
 mapping note;
 object ob=this_player();
 if (!ob->query_temp("bao_flag"))
   return notify_fail("不给钱怎行!\n");
//if ((int)query("note/time")-time()<60*60)
//return notify_fail("新通告颁布不久,如今不宜通告别的内容.\n");
        if(!arg) return notify_fail("通告请指定一个标题。\n");
        
        note = allocate_mapping(4);
        note["title"] = arg;
        note["author"] = this_player()->query("name");
        note["id"] = this_player()->query("id");
        note["time"] = time();
        this_player()->edit( (: done_post, this_player(), note :) );
        return 1;
}