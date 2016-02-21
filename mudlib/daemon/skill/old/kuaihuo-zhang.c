// songshan-sword.c
// Modified by Java Sep.1998
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "name":    "ʹ������",
        "action":  "$N����һȭֱ��,�����翪�Ʊ�,��ס�Է�����,���°���������.��[ʹ������]",
        "force":    50,
        "damage":  50,
        "damage_type":  "����"
]),
([      "name":    "�������",
        "action":  "$N����һ�Ʒ���$n����,���ư���,���Ƿ�ס$n����,����ֱȭ����$n�ؿ�",
        "force":   70,
        "damage":  80,
        "damage_type":  "����"
]),
([      "name":    "���»���",
        "action":  "$N������ֱ�濪,����$n����,���ֻӶ�,����$n����������Ѩ,����[���»���]",
        "force":   70,
        "damage":  100,
        "damage_type":  "����"
]),
([      "name":    "����Χ¯",
        "action":  "$Nʹ��[����Χ¯],˫����$n���屧ȥ,���г��ȼ���",
        "force":   80,
        "damage":  120,
        "damage_type":  "����"
]),
([      "name":    "������÷",
        "action":  "$Nʹ��[������÷],����������,бб��$n��������,������ָ����,
        ��÷֦б��,ָ��$n",
        "dodge":   90,
        "damage":  140,
        "damage_type":  "����"
]),
([      "name":    "�����þ�",
        "action":  "$N����ʹ�������Ź���,˫�ֳ�������״,Ƭ�̼���ָ��
        $n���,����һ��[�����þ�]",
        "dodge":   100,
        "damage":  160,
        "damage_type":  "����"
]),
([      "name":    "Ū������",
        "action":  "$N������ֱָ��,����$n������Ѩ,���ֳɺ��λ���,����[Ū������]",
        "dodge":   120,
        "damage":  180,
        "damage_type":  "����"
]),
});

int valid_learn(object me)
{
    object ob;
    if( (int)me->query("max_force") < 50 )
        return notify_fail("�������������û�а취�����ʮ���ơ�\n");
    if(ob = me->query_temp("weapon")
        return notify_fail("�����ʮ���Ʊ�����֡�\n");

    return 1;
}

int valid_enable(string usage)
{
    return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
    if( (int)me->query("kee") < 30
    ||      (int)me->query("force") < 5 )
        return notify_fail("�����������������û�а취��ϰ���ʮ���ơ�\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("�㰴����ѧ����һ����ʮ���ơ�\n");
    return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return __DIR__"kuaihuo-zhang/" + action;
}