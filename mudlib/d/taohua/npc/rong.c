inherit NPC;
void create()
{
        set_name("黄蓉", ({ "huang rong","rong"}));
        set("gender", "女性");
        set("age", 20);
        set("long", "天仙般的容貌，美伦美幻。一脸调皮的摸样。\n");
        
        set("per" , 40);
        set("str" , 30);
        set("combat_exp", 500000);
        set("attitude", "peaceful");
        
       set("chat_chance", 10);
        set("chat_msg", ({
                "蓉儿说道：哎！靖哥哥不知道现在怎么样了。。。\n",
                "蓉儿叹气道：真想见到他啊 哎！\n",

}));
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);

        setup();
        carry_object("/d/taohua/obj/huangyi")->wear();
        add_money("coin",100); 
}

