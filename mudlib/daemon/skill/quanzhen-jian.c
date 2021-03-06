// quanzhen-jian.c 全真剑法


inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「探海屠龙」，手中$w由左至右横扫向向$n的$l",
	"damage":50,
        "damage_type":  "割伤"
]),
([      "action":"$N踏上一步，「罡风扫叶」，手中$w盘旋飞舞出一道剑光劈向$n的$l",
	"damage":60,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w一抖，一招「顺水推舟」，斜斜一剑反腕撩出，攻向$n的$l",
	"damage":70,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w连绕数个大圈，一式「星弛电闪」，一道剑光飞向$n的$l",
	"damage":80,
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「白鹤亮翅」，左手伸展，右手$w挥向$n的$l",
	"damage":90,
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w斜指苍天，一式「横行漠北」，对准$n的$l斜斜击出",
	"damage":100,
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「马蹴落花」，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"damage":120,
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「九品莲台」，$w飞斩盘旋，如疾电般射向$n的胸口",
	"damage":140,
        "damage_type":  "刺伤"
]),
([      "action":"$N使一式「荆轲刺秦」，手中$w合身疾刺$n的胸口，威不可当",
	"damage":160,
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w划出一道长长的弧线，刺向$n的$l，却是一招「箫史乘龙」",
	"damage":180,
        "damage_type":  "刺伤"
]),
([      "action":"$N回剑自守，使一式「深藏若虚」，蓦地手中$w向$n击出",
	"damage":200,
        "damage_type":  "刺伤"
]),
([      "action":"$N左足踢起，一式「魁星踢斗」，$w从不可思议的角度刺向$n",
	"damage":220,
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「紫电穿云」，$w突然从天而降，一片金光围掠$n全身",
	"damage":250,
        "damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me) { return 1; }


mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
	if((int)me->query("kee")<50)
                return notify_fail("你的体力不够练全真剑法。\n");
	me->receive_damage("kee",25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}

int power_point()	{	return 1.5;	}
int hard_point()	{	return 2.5;	}

