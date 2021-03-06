#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit HANDS;

#include "message.h"

void create()
{
  set_name(HIG "短笛" NOR, ({ "duan di", "dizi"}));
  set_weight(800);
  set("material", "wood");
  set("long","翠绿的短笛,笛身粗短,与一般的笛子差别很大。\n");
  set("unit", "支");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  setup();
}

int init ()
{
  add_action ("do_wear", "wear");
  add_action ("do_remove", "remove");
  add_action ("do_play", "play");
  add_action ("do_play", "chui");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "di zi" && arg != "duan di")
    return 0;
  msg = "$N举笛就唇，清扬的笛声吹散了满天乌云。\n"; 
  flower->set("wear_msg",msg);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "duan di" && arg != "dizi")
    return 0;

  msg = "$N长叹一声,将"+name+"轻轻地收起来……\n"; 
  flower->set("unequip_msg",msg);
  return 0;
}

int do_play (string arg)
{
  object me = this_player();
  object flower = this_object();
  string name = flower->query("name");
  string msg;

  if (arg != "duan di"&& arg != "di zi")
    return 0;

  msg = "$N吹起"+name+",笛声如百灵一路飞扬。\n"; 
  message_vision (msg,me);
  return 1;
}
