// houquan.c 猴拳

inherit SKILL;

mapping *action = ({
([	"action" : "\n$单腿微曲，忽的向前扑出，一式「仙猴摘桃」，二爪直出，抓向$n的双眼",
	"damage":50,
	"damage_type" : "抓伤",
]),
([	"action" : "$N左手虚晃，一式「灵猴攀枝」，右手直击，反扣$n的肩井大穴",
	"damage":80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N一臂前伸，一臂后指，一式「猿臂轻舒」，攻向$n的两肋",
	"damage":110,
        "damage_type" : "瘀伤"
]),
([	"action" : "\n$N忽然缩成一团，使一式「八方幻影」，双掌无形无定，一爪抓向$n的胸口",
	"damage":140,
        "damage_type" : "内伤"
]),
([	"action" : "$N猛吸一口气，一弯腰，使一式「水中揽月」，双爪疾扣向$n的小腹",
	"damage":170,
        "damage_type" : "瘀伤",
]),
([	"action" : "$N猛的向上高高跃起，一式「落地摘星」，居高临下，一爪罩向$n的头骨",
	"damage":200,
        "damage_type" : "抓伤",
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练猴拳必须空手。\n");
	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候不够，无法学猴拳。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练猴拳。\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 10)
		return notify_fail("你的内力不够练猴拳。\n");
	me->receive_damage("kee", 15);
	me->add("force", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"houquan/" + action;
}

int power_point()	{	return 1.5;	}
