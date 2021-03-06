//七弦无形剑
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「弦外有音」，手中$w如一风一般卷向$n的$l",
                "dodge":                -20,
		"parry":		50,
		"damage":		100,
		"force":	100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N伸指在$w上一弹，趁$w轻响之际一招「庸人自扰」，剑光向残照般洒向$n的$l",
                "dodge":                -20,
			"damage":		110,
			"force":		100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「寂寞无声」，手中$w默默的削向$n的$l",
                "dodge":                -30,
			"damage":		120,
			"force":		110,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w一式「珠落玉盘」对准$n的$l一连刺出数剑",
		"damage":		130,
		"force":		110,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「有所思」刺向$n的$l",
                "dodge":                20,
		"damage":		140,
		"force":		120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「清心普善」反手对准$n$l一剑刺去",
                "dodge":                -20,
		"damage":		150,
		"force":		120,
                "damage_type":  "刺伤"
        ]),
	([	"action":
"$N忽然眼中精光四射，一招「六丁开山」，一阵寒气逼个的剑气直逼$n",
		"dodge":		20,
		"parry":		50,
		"damage":		200,
		"force":		150,
		"damage_type":		"内伤",
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
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object ob;
	        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
			return notify_fail("你必须先找一把剑才能练剑法。\n");
	if( (int)me->query("kee") <40)
                return 
	notify_fail("你的气不够，没有办法练习「七弦无形剑」。\n");
	me->receive_damage("kee",40);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("legend") + "/deisword/" + action;
}
 
string *parry_msg = ({
        "$n使出一招「望极春愁」，手中的$v荡开了$N的$w。\n",
        "$n使出「黯黯生天际」，将$N的$w封于丈外。\n",
        "$n使出一招「强乐还无味」，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「对酒当歌」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招「拟对强衣为」封住了$N的攻势。\n",
        "$n反手一招「伫望黯草无」，整个人消失在一团剑光之中。\n",
        "$n使出一招「倚极黯色言」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招招「把酒乐带伊」，迫得$N连连后退。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

