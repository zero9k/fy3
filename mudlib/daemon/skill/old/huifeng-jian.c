// 回风拂柳剑

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N一式「清风袭月」，剑锋平指，剑势如风，一气呵成猛攻$n的小腹！",
        "force" : 160,
        "dodge" : 20,
        "parry" : 5,
        "damage" : 25,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跃上一步，左手剑诀，右手$w使出一式「飘雪穿云」直刺$n的前胸！",
        "force" : 220,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 30,
        "lvl" : 10,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w斜指苍天，一式「千峰竞秀」，化出无数个剑尖，裹向$n的右脚",
        "force" : 250,
        "dodge" : 15,
        "parry" : 5,
        "damage" : 40,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「万流归宗」，$w自上而下缓缓划出一个大弧，突然从中向$n刺出！",
        "force" : 300,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 50,
        "lvl" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N回身拧腰，一式「乌龙搅柱」，$w随身平划，点向$n的胸腹要穴！",
        "force" : 330,
        "parry" : 5,
        "dodge" : 10,
        "damage" : 60,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「大雁啼沙」，全身贴地平飞，身剑合一，闪电般刺向$n的右臂！",
        "force" : 380,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 70,
        "lvl" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N施出「进退龙游」，$w脱手飞出，如游龙般翱翔青宇，破空射向$n的左肩！",
        "force" : 440,
        "dodge" : 20,
        "parry" : 15,
        "damage" : 85,
        "lvl" : 65,
        "damage_type" : "刺伤"
]),
([      "action" : "$N长啸一声，一式「天地鹤翔」，腾空飞起，全身迸出无数道雪亮剑芒，照耀天际！",
        "force" : 500,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 90,
        "lvl" : 80,
        "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("emei-xinfa", 1) < 20)
                return notify_fail("你的峨眉心法火候太浅。\n");
        if ((int)me->query_skill("parry", 1) < 10)
                return notify_fail("你的基本招架火候太浅。\n");
        return 1;
}


mapping query_action(object me,object target)
{
       
        int i, level;
        level   = (int) me->query_skill("huifeng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
        return action[random(sizeof(action))];

}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 20)
                return notify_fail("你的体力不够练回风拂柳剑。\n");
        me->receive_damage("kee", 20);
        if ((int)me->query("force") < 20)
                return notify_fail("你的内力不够练回风拂柳剑。\n");
        me->receive_damage("force",5);
        return 1;
}
           
string perform_action_file(string action)
{
        return __DIR__"huifeng-jian/" + action;
}
