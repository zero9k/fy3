// xian.c  云龙三现

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

        if(me->is_busy())
                   return notify_fail("你的上一个动作还没有完成。\n");
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("云龙三现只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
        if( (int)me->query_skill("yunlong-jianfa", 1) < 50 )
                return notify_fail("你的云龙剑法不够娴熟，不会使用「云龙三现」。\n");
	                        
        if( (int)me->query_skill("yunlong-xinfa", 1) < 50 )
                return notify_fail("你的云龙心法不够高，不能用来反震伤敌。\n");
			
        if( (int)me->query("force", 1) < 100 )
		return notify_fail("你现在内力太弱，不能使用「云龙三现」。\n");
			
	msg = CYN "$N微微一笑，猛吸一口气,欲使出以气驭剑绝技攻击$n。\n"NOR;


	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
                target->start_busy( (int)me->query_skill("yunlong-jianfa") / 30 + 1);
		
                damage = (int)me->query_skill("yunlong-xinfa", 1);
                damage = damage +  (int)me->query_skill("yunlong-xinfa", 1);
                damage = damage +  (int)me->query_skill("yunlong-jianfa", 1);
		
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/2);
		me->add("force", -damage);
		msg += HIR"只见$N手中剑光幻作一条金龙,腾空而起,倏的罩向$n,\n$n只觉一股大力铺天盖地般压来,登时眼前一花，两耳轰鸣,哇的喷出一口鲜血！！\n"NOR;
                me->start_busy(1);
	} else 
	{
		msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
		me->add("force", -100);
                   me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
