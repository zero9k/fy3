// taiji-quan.c ̫��ȭ

inherit SKILL;

mapping *action = ({
([	"action" : "$Nʹһ�С���ȸβ����˫�ֻ��˸���Ȧ������$n��$l",
	"force" : 150,
	"dodge" : 30,
	"skill_name" : "��ȸβ",
	"damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ�С��������š�����$n��$l��ȥ",
	"force" : 250,
	"dodge" : 25,
	"skill_name" : "��������",
        "damage_type" : "����"
]),
([	"action" : "$N˫����ȭ����ǰ��󻮻���һ�С�˫����������$n��$l",
	"force" : 300,
	"dodge" : 20,
	"skill_name" : "˫����",
        "damage_type" : "����"
]),
([	"action" : "$N�����黮������һ�ǡ�ָ�ɴ�������$n���ɲ�",
	"force" : 320,
	"dodge" : 15,
	"skill_name" : "ָ�ɴ�",
        "damage_type" : "����"
]),
([	"action" : "$Nʩ��������ʽ�������ֻ���$n��$l�����ֹ���$n���ɲ�",
	"force" : 370,
	"dodge" : 10,
	"skill_name" : "����ʽ",
        "damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
	if(me->query("max_force")<100)
		return notify_fail("�������̫�����޷���̫��ȭ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if(me->query("kee")<30)
		return notify_fail("�������̫���ˡ�\n");
	if(me->query("force")<20)
		return notify_fail("�������������̫��ȭ��\n");
	me->receive_damage("kee",25);
	me->add("force",-10);
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("daoshi")+"/taiji-quan/"+action;
}