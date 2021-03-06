inherit SKILL;

mapping *action = ({
([      "action" : "$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「翻云覆雨」",
        "damage_type" : "掌伤",
        "damage" : 15,
]),
([      "action" : "$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「排山倒海」双掌疾向$n脑后拍下",
        "damage_type" : "掌伤",
        "damage" : 25,
]),
([      "action" : "$N就地一滚，突然到了$n身前，使一招「风卷残云」，双掌直拍$n小腹",
        "damage_type" : "掌伤",
        "damage" : 35,
]),
([      "action" : "$N左掌护胸，右涨凝劲后发，一招「云过天晴」，缓缓托向$n的$l",
        "damage_type" : "掌伤",
        "damage" : 45 ,
]),
([      "action" : "$N微微一笑，疾速前扑，使一招「梦幻尘缘」，直拍$n胸前三大要穴",
        "damage_type" : "掌伤",
        "damage" : 55,
]),
([      "action" : "$N身形诡异，忽左忽右，陡然转到$n身后，一招「电光火石」，双手直向$n咽喉插下",
        "damage_type" : "掌伤",
        "damage" : 65,
]),
([      "action" : "$N一声长啸，身形突然拔起，使出「如水中月」，由半空盘旋下击，$n顿觉漫天掌影，罩向全身要穴",
        "damage_type" : "掌伤",
        "damage" : 95,
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练破云掌必须空手。\n");
        if ((int)me->query("max_force") < 80)
                return notify_fail("你的内力太弱，无法学破云掌。\n");
        if ((int)me->query("str") < 25)
                return notify_fail("你的臂力太差，无法学破云掌。\n");
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
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练破云掌。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
        return "/daemon/class/songshan/poyun-zhang/" + action;
}


