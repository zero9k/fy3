// 

inherit ITEM;

void create()
{
        set_name("《阴符经》", ({"yinfujing", "jing" }));
        set_weight(100);
        set("unit", "本");
        set("long",
                "小乘道学经典，一定要读一读.\n"
             );
        set("value", 1000);
        set("skill", ([
                "name": "daoxuexinde",
                "max_skill":    20 
        ]) );
}
 
