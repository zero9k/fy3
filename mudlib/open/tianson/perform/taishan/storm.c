// 暴风骤雨
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「暴风骤雨」？\n");

        if((int)me->query("force") < 50+(int)me->query("force_factor") )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

	if((int)me->query_skill("kuaihuo-zhang", 1) <50)
		return notify_fail("你的快活十三掌级别还不够！\n");


        me->add("force", -25-(int)me->query("force_factor"));
        me->receive_damage("kee", 50);

        if( random(me->query("max_force")) < 50 ) {
                write("糟糕，没成功！\n");
                return 1;
        }

	msg = HIC
"\n$N一反平常快活逍逸的神情，口中大喝了一声，施展出「暴风骤雨」，双掌上下翻飞，\n"
"$n只觉得四周都是$N双掌的影子，根本不知如何招架，更不用说躲闪了！\n\n" NOR;

        ap = me->query_skill("kuaihuo-zhang", 1);
        ap = ( ap * ap * ap / (4 * 400) ) + (int)me->query("kee");
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
	dp = ( dp * dp * dp / (4 * 400) ) + (int)target->query("kee");
	dp = dp*250 + target->query("combat_exp"); 
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_force") / 10 +
			random((int)me->query("eff_kee") /50);
                damage -= (int)target->query("max_force") / 10 +
			random((int)target->query("eff_kee") / 5);
		damage+=(int)me->query("force_factor")-random((int)target->query("force_factor"));
                if( damage > 0 ) {
		msg += HIC "结果一掌结结实实全部拍中了$n，几乎把$n的骨头都震散了！\n" NOR;
		damage +=random((damage*(int)me->query_skill("unarmed"))/50);
                        target->receive_damage("sen", damage, me);
   //这两行可伤最大值， target->receive_wound("sen", damage/4, me);
                        target->receive_damage("kee", damage, me);
   //可以考虑加或不加。 target->receive_wound("kee", damage/3, me);
                        me->improve_skill("kuaihuo-zhang", 1, 1);
                }
	    else {
		msg += HIC "结果被$n以内力反激，$N反而自受其苦，双手受伤不轻！\n" NOR;
		damage -= (int)target->query("force_factor");
		damage -=random((-damage*(int)target->query_skill("unarmed"))/80);
                        me->receive_damage("sen", -damage, target);
    //同上              me->receive_wound("sen", -damage/4, target);
                        me->receive_damage("kee", -damage, target);
    //                  me->receive_wound("kee", -damage/3, target);
 
                       me->improve_skill("kuaihuo-zhang", 1, 1);
	    }
             } 
	else
                msg += "但是被$n躲开了。\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}
