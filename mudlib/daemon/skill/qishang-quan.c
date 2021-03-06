// qishang-quan.c -七伤拳
// pal 1997.05.26

inherit SKILL;

mapping *action = ({
([	"action" : "$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l",
	"damage":130,
	"damage_type" : "内伤"
]),
([	"action" : "$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出",
	"damage":140,
        "damage_type" : "内伤"
]),
([	"action" : "$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪",
	"damage":150,
        "damage_type" : "内伤"
]),
([	"action" : "$N身形跃起，一式「火海刀山」，双拳当空击下，势不可挡",
	"damage":200,
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一矮，一式「土载万物」，两拳自下而上，攻向$n",
	"damage":160,
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一式「阴风惨惨」，攻向$n的身前身后",
	"damage":170,
        "damage_type" : "内伤"
]),
([	"action" : "$N移形换位，步到拳到，一式「阳光普照」，四面八方都是拳影",
	"damage":180,
        "damage_type" : "内伤"
]),
([	"action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式「七者皆伤」，骤然击向$n的前胸",
	"damage":190,
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	return 1;
}


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee")<30)
		return notify_fail("你的体力太低了。\n");
	if((int)me->query("force")<20)
		return notify_fail("你的内力不够练七伤拳。\n");
	me->receive_damage("kee",30);
	me->add("force",-10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}

int power_point()	{	return 1.75;	}
int hard_point()        {       return 3;	}
