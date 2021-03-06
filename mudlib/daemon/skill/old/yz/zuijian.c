// 醉剑，

inherit SKILL;

string *dodge_msg = ({
	"只见$n脚下一个不稳，差点摔倒，却刚好躲过了$N的攻击。\n",
});

mapping *action = ({
([      "action":"$N一个踉跄，酒壶险些脱手，慌乱之中无意刺向$n的要害。",
        "force" : 200,
        "dodge" : -100,
        "damage": 100,
        "skill_name" : "一醉方休",
        "damage_type":  "刺伤"
]),

([      "action":"$N左脚踩在右脚上，绊了自己一跟头，$w脱飞向$n的要害。",
        "force" : 100,
        "dodge" : -80,
        "damage": 100,
        "skill_name" : "醉生梦死",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}

mapping query_action(object me, object weapon)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                        return action[random(i)];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

