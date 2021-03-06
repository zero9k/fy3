// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［幽冥十八拍］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("unarmed") / 10 + 1;
	msg = HIR "$N使出[幽冥十八拍],双手幻出漫天血色掌印，飞雪似的向$n落来！" NOR;
	if( random(myexp * lvl) > yourexp )
	{
		message_vision(msg + "\n", me, target);
		msg = "结果$n连中数掌,暴起满天鲜血！\n";
		message_vision(msg, me, target);
             target->set("long","脸上一个"+HIR+"血红"+NOR+"的掌印,这是中了[幽冥血掌]所致!\n");
		target->unconcious();
	}
	else
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
	return 1;
}
