// sleep.c
// littlefish
// modify by musix 97.7

void wakeup(object,object);
void del_sleeped(object);

int main(object me, string arg)
{
	mapping fam;
	object where = environment(me);
	int ttt;

        seteuid(getuid());

	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
             && !(where->query("sleep_room"))
             || (where->query("no_sleep_room")) )
             return notify_fail("在这里睡觉好象不太合适。\n");
   
	if (me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("你找死啊！\n");
        
	if (where->query("hotel") && !(me->query_temp("rent_paid")))
	{
		message_vision("店小二从门外对$N大叫: 有没搞错啊! 付钱后再来睡!\n",me);
		return 1;
	}
 
	if (me->query_temp("sleeped"))
		return notify_fail("别睡啦！多睡对身体有害无益! \n");

	if (where->query("sleep_room"))
	{
		write("你迷迷糊糊打了个盹，不觉睡着了。\n");
	//	write("不一会儿，你就进入了梦乡。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N打了个哈欠，头一歪就进入了梦乡。\n",me);
	}
	else { 
		write("你往地下角落一躺，开始睡觉。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N头一歪，不一会便鼾声大作，做起梦来。\n",me);
	}

	where->set("no_fight", 1);
	where->add_temp("sleeping_person", 1);

	me->set("no_get", 1);	
	me->set("no_get_from", 1);	
	
	if (!(where->query("hotel"))) 
		me->set_temp("sleeped",1);
	else
		me->delete_temp("rent_paid");

	me->disable_player("<睡梦中>");
        ttt= me->query_con() ;
        if(ttt>40) ttt=40 ;
//	call_out("wakeup",random(45 - me->query("con")) + 45, me, where);
        call_out("wakeup",random(50 - ttt) , me, where);        
	return 1;
	
}

void wakeup(object me,object where)

{

	me->set("kee",  me->query("eff_kee"));
	me->set("gin",  me->query("eff_gin"));
	me->set("sen",me->query("eff_sen"));
	me->enable_player();
  
	call_out("del_sleeped", 119, me);

	message_vision("$N一觉醒来，也不知睡了多久。\n",me);
	me->set_temp("block_msg/all", 0);
	write("你一觉醒来，感觉好多了。\n");

	if (!where->query("sleep_room") && !where->query("hotel"))
		where->delete("no_fight");
     
	where->add_temp("sleeping_person", -1);
	me->delete("no_get");	
	me->delete("no_get_from");	
 
}

void del_sleeped(object me)
{
	if (objectp(me) &&  me->query_temp("sleeped"))
		me->delete_temp("sleeped");
}
