// wuji-jianfa.c 
// 无极剑法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               "$N使一招「蹋步回环」，手中$w一招跟一招，一步接一步，快如惊虹向$n的$l",
		"dodge":		20,
            "damae":          30,
            "force":          25,
            "parry":          40,
		"damage_type":	"刺伤"
	]),
        ([      "action":               "$N手中$w贴地如流，身形半立半跪，一式「伏地撩阴」向$n的$l",
		"dodge":	      20,
		"damae":		30,
            "force":          30,
            "parry":          25,
		"damage_type":	"割伤"
	]),
        ([     "action":		"$N一招「东风洗柳」，手中$w一闪，直向$n的$l划来",
		"dodge":		30,
		"damae":		20,
            "force":          30,
            "parry":          35,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N连人带$w，招走「回山环中」对准$n的$l刺出一剑",
            "damae":          30, 
		"dodge":		40,
            "parry":          35,
            "force":          40,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N吸气凹胸，反向微退，右手$w一招「彗星衫芒」对准$n的$l斜斜刺出一剑",
		"dodge":		40,
            "damae":          25,
            "force":          40,
            "parry":          45,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N左手掐诀，一个箭步，$w走「眉心点赤」一招，刺向$n的$l",
		"dodge":		20,
		"damage":		40,
            "parry":          50, 
            "force":          30,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N身子向后落退一步，右手$w一穿一翻，使一招「流星飞坠」猛向$n$l砸来",
		"dodge":		20,
		"damage":		20,
            "parry":          50,
            "force":          45,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使一招「风摆梨花」，双脚原地不动，上半身一个闪转，手中$w一沉向$n的$l卷来",
		"dodge":		30,
		"damage":		10,
            "force":          30, 
            "parry":          35, 
		"damage_type":	"割伤"
	]),
});

int valid_learn(object me)
{
        object ob;

                if( (int)me->query_skill("xiantian-force", 1) < 50 )
                return notify_fail("你的先天气功火候不足，无法练无极剑法
。\n");

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练无极剑法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("你的内力或气不够，没有办法练习无极剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍无极剑法。\n");
        return 1;
}
