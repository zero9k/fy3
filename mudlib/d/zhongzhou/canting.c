//canting

inherit ROOM;
void create()
	{
        set("short", "自助餐厅");
        set("long", @LONG
一进自助餐厅你就看见人来人往，每人门前有一个热腾腾的锅子。都
想看看自己的手艺如何。如你对烹调还不很内行的话，可以看看墙上的家
常菜谱(pu)。
LONG
        );
	  set("exits", ([
   	 "north"  : __DIR__"yanlingdong",

]));
	set("objects" , ([
		__DIR__"npc/lilaoban" : 1,
	]));
        set("item_desc", ([
                        "pu" :
"            家   常   菜   谱   大    全
	家常豆腐-----------豆腐，辣椒，盐，香油。
	红烧兔肉-----------新鲜兔肉，酱油，盐，香油。
	
\n"]));

        setup();
	}
void init()
{
	add_action("do_shao","烧豆腐");
	add_action("do_shao1","烧兔肉");
}

int do_shao()
{
object ob1,ob2,ob3,ob4;
object me;
me = this_player();
ob1 = present("yan",me);
ob2 = present("xiangyou",me);
ob3 = present("doufu",me);
ob4 = present("lajiao",me);
if( ob1 && ob2 && ob3 && ob4)
{
message_vision("$N淋上香油，放入豆腐和辣椒，撒上盐巴烧了起来！\n",me);
destruct(ob1);
destruct(ob2);
destruct(ob3);
destruct(ob4);
call_out("give_shao",random(3)+1,me);
return 1;
}
return 0;
}

int give_shao(object me)
{
object shao;
if(me) 
if( environment(me) == this_object())
{
shao = new(__DIR__"obj/jcdf");
if(shao->move(me))
message_vision("$N你把烧好的家常豆腐打好包放在身边。\n",me);
}
return 1;
}


int do_shao1()
{
object ob1,ob2,ob3,ob4;
object me;
me = this_player();
ob1 = present("yan",me);
ob2 = present("xiangyou",me);
ob3 = present("jiangyou",me);
ob4 = present("turou",me);
if( ob1 && ob2 && ob3 && ob4)
{
message_vision("$N把新鲜的兔肉放入锅中，有微火开始炖起来！\n",me);
destruct(ob1);
destruct(ob2);
destruct(ob3);
destruct(ob4);
call_out("give_shao1",random(3)+1,me);
return 1;
}
return 0;
}

int give_shao1(object me)
{
object shao1;
if(me) 
if( environment(me) == this_object())
{
shao1 = new(__DIR__"obj/turou1");
if(shao1->move(me))
message_vision("香喷喷的兔肉烧好了，$N把它放在怀里。\n",me);
}
return 1;
}

