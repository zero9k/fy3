// chan 泰山缠剑式 

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra;
        mapping map;
      object weapon;
        if( !target ) target = offensive_target(me);

        extra = me->query_skill("shibapan-jianfa",1);
        if ( extra < 60) return notify_fail("你的十八盘剑法还不够纯熟！\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("缠剑式只能对战斗中的对手使用。\n");

        if (me->query("force")<=100) return notify_fail("你的内力不足，无法使用缠剑决！\n");
      if(!objectp(weapon=me->query_temp("weapon"))||
      (string)weapon->query("skill_type")!="sword")
            return notify_fail("缠剑式只有用剑才能发挥威力。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "已经自顾不暇了，放胆攻击吧！\n");

        msg = CYN "$N使出泰山十八盘剑法之缠剑式，一把剑闪出十八道剑影";

        me->start_busy(1);
        if( random(me->query("combat_exp")+me->query_skill("shibapan-jianfa",1)*1000) 
       > (int)target->query("combat_exp")/3*2 ) {
                msg += "结果$n被缠个动弹不得！\n" NOR;
                target->start_busy( (int)me->query_skill("shibapan-jianfa") / 30 + 2);
        } else {
                msg += "可是$n看破了$N的剑招，一拧身跃出了剑影。\n" NOR;
            msg += "$n却一下失去平衡，反陷入了被动。\n" NOR;
        me->add("force",-100);
        me->add("sen",-10);
              me->start_busy(2);
      }
        message_vision(msg, me, target);

        return 1;
}

