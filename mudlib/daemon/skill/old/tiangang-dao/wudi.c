// wudi.c 天罡无敌

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
 
	if( !me->is_fighting() )
                return notify_fail("「天罡无敌」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("force") < 100 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("blade") < 100 ||
            me->query_skill_mapped("blade") != "tiangang-dao")
                return notify_fail("你的天罡无敌刀还不到家，无法使用「连环」！\n");

        msg = HIG"$N双手一震，一招「天罡无敌」，五式合一连绵劈向$n \n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));

	me->add("force", -100);
        me->start_busy(random(5));

	return 1;
}
