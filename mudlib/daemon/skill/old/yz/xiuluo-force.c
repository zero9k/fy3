// xiuluo-force.c 修罗阴煞功 by ksusan 10/03/97
#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("修罗阴煞功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

//	 string perform_action_file(string action)
//	{
//	 return CLASS_D("xiake")+"/suiyu-force/"+action;
//	}
string exert_function_file(string func)
{
	return CLASS_D("xiake")+"/xiuluo-force/"+func;
}
void skill_improved(object me)
{
        if(me->query_skill("xiuluo-force",1)==10)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第一重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==20)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第二重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==40)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第三重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==60)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第四重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==80)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第五重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==100)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第六重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==120)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第七重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==140)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第八重境界！\n"NOR);
        if(me->query_skill("xiuluo-force",1)==160)       
	       tell_object(me,HIC"你的修罗阴煞功已达到第九重境界！\n"NOR);
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap,dp;
	me->add("force",-factor);
	if(victim->is_busy())	return;
	if(factor<5)	return;
	if(victim->query("force")>me->query("force"))	return;
	ap=me->query_skill("force")+me->query_skill("dodge");
	dp=victim->query_skill("parry")+me->query_skill("dodge");
	if(random(ap)<random(dp))	return;
	victim->start_busy(factor/10+3);
	return BLU"只见$N运起修罗阴煞功，一股阴森寒气笼罩迫向四周。。\n$n手足冰冷的仰天打个『喷嚏』，行动迟缓起来！\n"NOR;
}
