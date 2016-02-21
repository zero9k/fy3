inherit FORCE;

int valid_enable(string usage)
{
        return usage == "force";
}

int valid_learn(object me)
{
	int nf;
        nf = (int)me->query_skill("force", 1);

        if ( nf < 15)
 return notify_fail("你的基本内功火候还不够，无法领会峨眉心法。\n");
          return 1;
}


int practice_skill(object me)
{
        return notify_fail("峨眉心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
return "/daemon/class/emei/emei-xinfa/" + func;
}

int power_point()	{	return 1.5;	}
