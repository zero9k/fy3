#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("天外飞龙只能对战斗中的对手使用。\n");

                
        if( (int)me->query_skill("huashan-jianfa",1)< 60)
        return notify_fail("你的华山剑法不够娴熟，不会使用天外飞龙。\n");
        if( (int)me->query_skill("zixia-shengong",1)< 60)
        return notify_fail("你的紫霞神功不够深厚，不会使用天外飞龙。\n");
                        
        if( (int)me->query("force")<200)
        return notify_fail("你现在内力太弱，不能使用天外飞龙。\n");
        if(me->query_temp("have_pfm"))
        return notify_fail("你刚展施完特殊招式，内息还没调整过来。\n");
        me->set_temp("have_pfm",1);

        msg = CYN "$N心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n刺了出去。\n"NOR;
        if(random(me->query("combat_exp"))>target->query("combat_exp")/3)       {

        target->start_busy(random(3));
        damage=(me->query_str()-target->query_con())*random(me->query_cor());
        if(damage<0)    damage=10;
	if( damage>600)	damage=600;
                
        target->receive_damage("kee",damage,me);
        target->receive_wound("kee",damage/3,me);
        me->add("force",-damage/5);
	if( (int)me->query("force")<0)	me->set("force",0);

        if( damage < 40 ) msg += HIC"结果$n被$N刺中一剑，闷哼一声。\n"NOR;
        else if( damage < 60 ) msg += HIY"结果$n被$N连刺数剑，血流满地。\n"NOR;
        else if( damage < 120 ) msg += RED"$n疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃拦腰而过，鲜血飞溅，皮肉卷起！！\n"NOR;
        else msg += HIR"结果$n被$N的剑气穿心，眼前一黑，身子向后飞出丈许！！\n"NOR;
        } else 
        {
        me->start_busy(1);
        me->add("force",-50);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);
        call_out("do_reset",3,me);
        return 1;
}

void do_reset(object me)
{
        if( !objectp(me))       return;
        if( (int)me->query_temp("have_pfm"))
                me->delete_temp("have_pfm");
}
