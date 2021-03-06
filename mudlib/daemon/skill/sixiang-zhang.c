inherit SKILL;
#include <ansi.h>
mapping *action = ({
([      "action" : "$N向$n遥遥一鞠，一式「三阳开泰」，双掌大开大阖，挡开$n的进击！",
        "damage_type" : "瘀伤",
	"damage":50,
]),
([      "action" : "紧跟着$N面含微笑，一式「五气呈祥」，双掌云缠雾绕，同时攻向$n全身各处！",
        "damage_type" : "瘀伤",
	"damage":80,
]),
([      "action" : "$N划身错步，一式「逆流捧沙」，双掌内拢外托，攻向$n的左肩！",
        "damage_type" : "劈伤",
	"damage":110,
]),
([      "action" : "$N一式「雷洞霹雳」，双掌以迅雷不及掩耳之势，劈向$n的两额太阳穴！",
        "damage_type" : "瘀伤",
	"damage":140,
]),
([      "action" : "$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的后背斫去",
        "damage_type" : "劈伤",
	"damage":170,
]),
([      "action" : "$N一式「梵心降魔」，双掌似让非让，似顶非顶，气浪如急流般使$n陷身其中！",
        "damage_type" : "瘀伤",
	"damage":200,
]),
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        return 1;
}


mapping query_action(object me)
{
        int i, level, force, ljz, sxz, unarmed;
        force = me->query("force");
        sxz = me->query_skill("sixiang-zhang", 1);
        ljz = me->query_skill("emei-xinfa", 1);
        unarmed = me->query_skill("unarmed", 1);
        if (ljz > 79 && sxz > 79 && unarmed > 79 && force > 500
            && random(me->query_int()) > 24 ){
                me->add("force", -60);
                if(random(10) < 2 )
                return ([
                "action":HIY
    "霎时间,日丽风静，云海平铺，美丽以极。阳光从$N背面斜射下来，形成彩色光环，$N见到自己的身影清晰地出现在银色世界上。"HIC"『光环随人动，人影在环中』"HIY",使出了"HIW"四象掌绝学"HIY"『金顶佛光』"NOR,
		"weapon" : HIY"金顶佛光"NOR,
		"damage":300,
                "damage_type": "瘀伤"]);
          }
	return action[random(sizeof(action))];

}

int practice_skill(object me)
{
        if ((int)me->query("gin") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("kee") < 20)
                return notify_fail("你的内力不够练四象掌。\n");
        me->receive_damage("gin", 15+random(10));
        me->add("force", -5+random(5));
        return 1;
}

string perform_action_file(string action)
{

    return "/daemon/class/emei/sixiang-zhang/" + action;

}
