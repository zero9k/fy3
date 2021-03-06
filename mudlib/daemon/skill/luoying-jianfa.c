// luoying-sword.c by ksusan 07/08/1997
// 97/9/27 by Aug

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「海天一色」，一剑飘向$n的$l",
		"damage":	100,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一招「雷霆万钧」，一剑砍向$n的$l",
		"damage":	110,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出「一剑穿心」，一道白光闪向$n的心脏",
		"damage":	120,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N吐气扬声，使出「落英缤纷」，数十把$w向$n的$l斩去",
		"damage":	130,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N微微一笑，使出「招花引蝶」，手中$w不着边际的刺出，可招招都落在了$n的身上",
		"damage":	140,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一式「雷厉风行」，手中$w卷起一阵狂风袭向$n",
		"damage":	150,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一飞冲天，一式「洋洋洒洒」点向$n三十六大死穴",
		"damage":	150,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N身行一闪，$n顿时看到数十把$w从四面八方袭来，缺不见了$N的身形，好一招「如鱼得水」",
		"damage":	160,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIW"$N神色凝重，$w"+HIW"平刺，使出「乾坤一剑」，瞬时天地为之一黯"NOR,
		"damage":	170,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIW"$N一连向$n刺出九剑，把$n裹在剑网之中，再也分不清东西南北，好一招「如醉如梦」"NOR,
		"damage":	180,
		"damage_type":	"刺伤"
	]),
	([	"action":		HIW"$N一招「源源不绝」使出，联绵不断的向$n刺出三十六剑，$n被搞的手忙脚乱，应接不暇"NOR,
		"damage":	190,
		"damage_type":	"刺伤"
	]), 
	([	"action":		HIW"$N一招「风花雪月」使出，$n顿时感到一股寒气袭了，似乎到了冰天雪地之中"NOR,
		"damage":	200,
		"damage_type":	"刺伤"
	]),
	([	"action":		YEL"$N脸色一变，不再顾忌自身的安危，一招「天地同寿」身剑合一向$n刺去"NOR,
		"damage":	210,
		"damage_type":	"刺伤"
	]),
	([	"action":		YEL"$N哈哈大笑，手中$w"+YEL"随随便便的挥向$n，「惟我独尊」使出，$N充满了自信",
		"damage":	220,
		"damage_type":	"刺伤"
	]),

});

int valid_learn(object me)
{
        object ob;

		if( (int)me->query_skill("suiyu-force", 1) < 20 )
			return notify_fail("你的碎玉神功火候不足，无法练落英剑法。\n");
		
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练落英剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
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
notify_fail("你的内力或气不够，没有办法练习落英剑法。\n");
        me->receive_damage("kee", 20);
        me->add("force", -3);
        write("你按著所学练了一遍落英剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
	return __DIR__"luoying-jianfa/"+action;
}
int power_point()	{	return 1.75;	}
int power_hard()	{	return 3;	}

