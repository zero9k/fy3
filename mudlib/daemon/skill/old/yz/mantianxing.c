//满天星

#include <ansi.h>

inherit SKILL;
mapping *action = ({
	([	"name":			"心言手语",
		"action":
"$N使一招「连环劫」，手中数个$w朝$n的$l飞去",
		"dodge":		-10,
		"damage":	100,
		"force":	100,
		"damage_type":	"刺伤"
	]),
	([	"name":			"星星点灯",
		"action":
"$N身形一转，一招「四连星」$w幻出四点，从不同方向飞奔$n的$l",
		"dodge":		-50,
		"damage":	110,
		"force":	100,
		"damage_type":	"戳伤"
	]),
        ([      "name":                 "风雨无阻",
		"action":
"$N身形微侧，一招「倒脱靴」，不知从何处飞出个$w，直扑$n的$l而去",
                "dodge":                -50,
		"damage":		120,
		"force":		110,
                "damage_type":  "戳伤"
        ]),
	([	"name":			"爱如潮水",
		"action":
"$N一招「接不归」，手中$w如离弦之剑飞向$n的$l",
		"dodge":		-30,
		"damage":	130,
		"force":	110,
		"damage_type":	"戳伤"
	]),
	([	"action":
"$N身形高高跃起，一式「大飞」$w从空中点向$n的$l",
		"damage":	140,
		"force":	120,
		"damage_type":	"刺伤",
	]),
	([	"action":
"$N突然连发两个$w，正是「双活」式，不给$n喘息之机直奔$l而来",
		"damage":	150,
		"force":	120,
		"damage_type":	"戳伤",
	]),
	([	"action":
"$N威喝一声，突使「连扳」招式，$w带着呼呼风声向着$n有$l飞来",
		"dodge":	-100,
		"damage":	200,
		"force":	150,
		"damage_type":	"内伤",
	]),
});

int valid_learn(object me)
{
    if(me->query_skill("xuantian-quan",1)<20)
        return notify_fail("你的「玄天拳法」不够娴熟。\n");
    if(me->query_skill("xuantian-neigong",1)<20)
    return notify_fail("你的「玄天内功」功力不够。\n");
    if(me->query("max_force")<50)
    return notify_fail("你的内力修为不够。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="throwing"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
    if( !(ob = me->query_temp("weapon"))
    ||  (string)ob->query("skill_type") != "throwing" )
        return notify_fail("你必须先找一支镖才能练。\n");
	if( (int)me->query("kee") < 40)
	return notify_fail("你的气不够，没有办法练习。\n");
	me->receive_damage("kee", 40);
	return 1;
}


