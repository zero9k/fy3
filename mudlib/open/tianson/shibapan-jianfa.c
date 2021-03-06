// taishan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([
        "action":  "$N右手$w斜指而下，左手五指正在屈指而数，从一数到五，握而成拳，又
将拇指伸出，次而食指，终至五指全展，跟着又屈拇指而屈食指，再屈中
指，然后手中$w剑光暴长，向$n的$l刺去",
	"damage":80,
        "damage_type":  "刺伤"
]),
([
        "action":  "$N手中$w一晃，向右滑出三步，一招“朗月无云”，转过身来，身
子微矮，$w向$n斜斜刺去",
	"damage":110,
        "damage_type":  "刺伤"
]),
([
        "action":  "$N手中$w圈转，一招「峻岭横空」去势奇疾，无数剑光刺向$n的$l",
	"damage":140,
        "damage_type":  "刺伤"
]),
([
        "action":  "$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地
$w剑光暴长，一招「泰山十八盘」往$n$l刺去",
	"damage":170,
        "damage_type":  "刺伤"
]),
([
        "action":  "$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数
古朴，内藏奇变，正是「五大夫剑」",
	"damage":200,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
    object ob;
	if( (int)me->query("max_force")<50)
        return notify_fail("你的内力不够，没有办法练泰山剑法。\n");
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
	if((int)me->query("kee")<30
	|| (int)me->query("force")<5)
        return notify_fail("你的内力或气不够，没有办法练习泰山剑法。\n");
	me->receive_damage("kee",30);
	me->add("force",-5);
    write("你按著所学练了一遍泰山剑法。\n");
    return 1;
}


string perform_action_file(string action)
{
        return "/daemon/class/taishan/shibapan-jianfa/"+action;
}

   int power_point()       {       return 1.5;     }
   int hard_point()        {       return 2;       }

