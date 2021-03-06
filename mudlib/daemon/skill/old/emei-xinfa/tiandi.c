#include <ansi.h>

int exert(object me, object target)
{      if( me->is_fighting() || target->is_fighting())
                return notify_fail("战斗中无法运功疗伤！\n");

        if( !target || target == me)
              {if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

              if (me->is_busy() )
                return notify_fail("你正忙着哪！\n");

               if ((int)me->query_skill("emei-xinfa", 1) < 30)
                return notify_fail("你的峨眉心法修为还不够。\n");
               if( (int)me->query("force") < 30 )
                return notify_fail("你的真气不够。\n");
               if( (int)me->query("eff_kee") >= (int)me->query("max_kee")  )
                return notify_fail("你没有受伤。\n");
               if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 5 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

               write(HIY"你习地而做，默念峨眉心法「天地」诀，运起峨眉心法功开始疗伤。\n" NOR);
               message_vision(HIW"只见$N吐出一口瘀血，脸色看起来好多了。\n" NOR,me);

               me->receive_curing("kee", 10 + (int)me->query_skill("force") / 5 );
               me->add("force", -30);
               me->set("force_factor", 0);

               return 1;
              }


        if( (int)me->query("max_force") < 300 )
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("force") < 150 )
                return notify_fail("你的真气不够。\n");

        if( (int)target->query("eff_lee") < (int)target->query("max_kee") / 10 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起天地灵气之震荡！\n");
       if( (int)target->query("eff_kee") >= (int)target->query("max_kee") )
              return notify_fail( target->name() + "看上去好象没有什么外伤,似乎不用治疗了。\n");
        message_vision(
 MAG "$N习地而做，默念峨眉心法「天地」诀，运起峨眉心法开始为$n疗伤... \n"
                "$N将天地之灵气聚于掌心,一掌拍在$n天灵盖,一掌按在$n背心,将聚的得的灵气缓缓输入$n体内...  \n"
              "过了不久,只见$n身旁开始出现丝丝白气,而且越来越浓... \n\n"
              "只见$n吐出一口瘀血，脸色看起来好多了。 \n" NOR,
                me, target );

        target->receive_curing("kee", 20 + (int)me->query_skill("force")/2 );
       target->receive_curing("gin", 10 + (int)me->query_skill("force")/3 );
        target->add("kee", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("kee") > (int)target->query("eff_kee") ) target->set("kee", (int)target->query("eff_kee"));

        me->add("force", -150);
        me->set("force_factor", 0);
                me->start_busy(1);
                target->start_busy(5);
        return 1;
}
