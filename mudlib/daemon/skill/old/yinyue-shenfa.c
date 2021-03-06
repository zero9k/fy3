// yinyue-shenfa.c
//隐月身法

inherit SKILL;

string *dodge_msg = ({
        "$n一招「燕飞纵云」双脚一点，疾如飞燕纵起一丈多高，使$N一招落空。\n",
        "只见$n斜身上部一式「寒蝉移枝」早已闪开$N的攻击。\n",
        "$n使出「颠倒八仙」身子往下面一伏,就势一转,躲到$N背后。\n",
        "$n脚尖点地,拔起七八尺高,横身一闪落在丈外，一招「鲤鱼跳龙门」已避了开去。\n",
        "可是$n使一招「风摆玉莲」，身行左右一晃，令$N看花了眼,无丛下手。\n",
        "$n身体前倾,双脚连蹬地面，一招「悬瀑三叠」从$N右肩飞掠而过。\n",
        "但是$n一招「细胸巧翻云」使出，倒翻出三丈开外，令$N鞭长莫及！\n"
});
string *dodge_msg_low = ({
        "$n一招「燕飞纵云」双脚一点，疾如飞燕纵起一丈多高，使$N一招落空。\n",
        "只见$n斜身上部一式「寒蝉移枝」早已闪开$N的攻击。\n",
        "$n使出「颠倒八仙」身子往下面一伏,就势一转,躲到$N背后。\n",
        "$n脚尖点地,拔起七八尺高,横身一闪落在丈外，一招「鲤鱼跳龙门」已避了开去。\n",
        "可是$n使一招「风摆玉莲」，身行左右一晃，令$N看花了眼,无丛下手。\n",
        "$n身体前倾,双脚连蹬地面，一招「悬瀑三叠」从$N右肩飞掠而过。\n",
        "但是$n一招「细胸巧翻云」使出，倒翻出三丈开外，令$N鞭长莫及！\n"
});
 
int valid_enable(string usage) { return (usage == "dodge");}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
               return notify_fail("你的体力太差了，无法练习隐月身法。\n");
               me->receive_damage("kee",30);
        return 1;
}

