// created by tianson 

inherit ITEM;

void create()
{
  set_name("烂泥", ({"lan ni", "ni"}));
  set_weight(1500);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "堆");
    set("long", "一堆没人会注意的烂泥。\n");
    set("material", "stone");
  }
  setup();
}
