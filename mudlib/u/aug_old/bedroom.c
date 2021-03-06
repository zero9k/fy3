// lu:bedroom.c
// 97.7.27 by Aug

inherit ROOM;

int HAVE_ONE=1;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这里是陆庄主的寝室。别看陆家庄富甲一方，陆庄主的寝室倒是十分
简朴，只有一床一几。但屋内收拾的干干净净、整整齐齐，看了就叫人舒
服。门楣上斜斜的钉这副铁八卦 (bagua)。屋子的北面有扇门通向后花园，
南面是大厅。
LONG
	);

	set("item_desc", 	([
		"八卦" : "这是练劈空掌用的铁八卦，但钉的有点斜，看来陆庄主对这门高深武功的研究还不够。\n",
		"bagua" : "这是练劈空掌用的铁八卦，但钉的有点斜，看来陆庄主对这门高深武功的研究还不够。\n",
	]));
      
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"hall",
		"north" : __DIR__"garden",
	]));

	set("outdoors", "lu_town");

	setup();
}

void init()
{
	add_action("do_hit", "hit");
}

int do_hit(string arg)
{
    object me;

    if((arg!="bagua")&&(arg!="铁八卦")) return 0;
    
    me=this_player();
    message_vision("$N一提气，奋力飞身向铁八卦击去。\n",me);
    if(random(me->query_skill("dodge"))>50)
    {   
      write("你把铁八卦打正了，墙上突然出现一个暗格，");
      if(HAVE_ONE==1) 
      {
        write("里面有一把宝剑。\n");

        if( me->over_encumbranced() ) 
          write("但你已经负荷过重了，没法再拿剑了 :-( \n");
        else
        {
          new(__DIR__"obj/zhuifeng")->move(me);
          write("你拿到一把追风剑。\n");
          HAVE_ONE=0;
        }
        
        write("过了一会儿，暗门又慢慢关上了。\n");
      }
      else 
        write("但里面什么也没有。\n过了一会儿，暗门又慢慢关上了。\n");
    }
    else
    {
      write("不料你摔了个狗吃屎。\n");

      me->set("eff_kee", me->query("max_kee")/5+
		random(me->query("max_kee")/5) ); 
    } 

    return 1;
}
