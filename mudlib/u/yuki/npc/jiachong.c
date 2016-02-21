inherit NPC;

void create()
{
        set_name("甲虫", ({ "jiechong", "jiachong" }) );
        set("race", "野兽");
        set("age", 2);
        set("long", "一只小金壳甲虫，正在恶狠狠的盯着你。\n");
        set("attitude", "killer");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "头部","背甲" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 200);

        set_temp("apply/attack", 5);
        set_temp("apply/damage", 3);
        set_temp("apply/defence",5);
        set_temp("apply/armor",2);

        setup();
}

void die()
{
        object ob;
        message_vision("$N被打的壳碎头破，死了。\n", this_object());
        destruct(this_object());
}
