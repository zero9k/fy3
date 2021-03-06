// yizhi-chan.c 一阳指


inherit SKILL;

mapping *action = ({
([      "action" : "$N右手四指屈回，小指猛地点向$n的胸口要穴，却是一招「秦塞通烟」",
	"damage":50,
        "damage_type" : "内伤"
]),
([      "action" : "$N右手小指划了个小弧线，接着划向$n的$l,是一招「冲波逆折」",
	"damage":70,
        "damage_type" : "内伤"
]),
([      "action" : "$N转身回头，一式「太白横绝」，右手无名指反手疾点$n的$l",
	"damage":90,
        "damage_type" : "内伤"
]),
([      "action" : "$N使一式「黄鹤之飞」，右手无名指轻飘飘地点向$n的$l",
	"damage":110,
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「地崩山摧」，右手中指连划数圈，罩向$n的上身数十大穴",
	"damage":130,
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「青泥盘盘」，左手连划数圈，右手中指突然自圈中穿出，直刺$n的$l",
	"damage":130,
        "damage_type" : "内伤"
]),
([      "action" : "$N右手食指连点数点，合身刺向$n的背心大穴，却是一式「天梯石栈」",
	"damage":150,
        "damage_type" : "内伤"
]),
([      "action" : "$N使「以手抚膺」右手食指虚虚点向$n的胸口，将$n胸口的所有大穴都笼罩在指力之下",
	"damage":170,
        "damage_type" : "内伤"
]),
([      "action" : "$N右手拇指直立，遥遥对着$n一捺，一道劲气直奔$n而去，是一式「六龙回日」",
	"damage":190,
        "damage_type" : "内伤"
]),
([      "action" : "$N大喝一声，右手拇指按向$n，威不可当，却是一式「青天明月」",
	"damage":210,
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练一阳指必须空手。\n");
        if ((int)me->query_skill("kurong-changong", 1) > 80 ||
            (int)me->query_skill("xiantian-qigong", 1) > 80)
                return 1;
        else
                return notify_fail("你的本门内功火候不够，无法学一阳指。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if((int)me->query("kee")<30)
                return notify_fail("你的体力太低了。\n");
	if((int)me->query("force")<25)
                return notify_fail("你的内力不够练一阳指。\n");
	me->receive_damage("kee",25);
	me->add("force",-10);
        return 1;
}

string perform_action_file(string action)
{
return "/daemon/class/dali/yiyang-zhi/" + action;
}

int power_point()	{	return 1.75;	}
int hard_point()	{	return 2;	}

