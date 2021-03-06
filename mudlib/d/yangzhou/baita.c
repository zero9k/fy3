// Room: /u/swordman/yangzhou/baita.c

inherit ROOM;

void create ()
{
  set ("short", "白塔晴云");
  set ("long", @LONG
        "名园依绿水，仙塔俪云庄”
    白塔的来历有一个传说：扬州盐业鼎盛时期，扬州盐运史在京曾向皇上
夸口说扬州也有和北京一样的白塔，皇上性起，立刻摆架南巡。扬州为搪塞
欺君之罪，用盐赶造了此塔，和北京遥遥相望。据说至今塔下的泥土都有咸
味。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youke" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedao3",
]));
  set("light_up", 1);

  setup();
}
