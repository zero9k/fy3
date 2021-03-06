// Room: /u/swordman/yangzhou/jiedao1
inherit ROOM;

void create ()
{
  set ("short", "瘦西湖");
  set ("long", @LONG
        “两岸花柳全依水，一路楼台直到山”
    这里就是以清秀典雅著称的瘦西湖山庄，庄内碧水绿草，亭台水榭，
白塔楼桥，歌舞相闻。联题“风月无边，到此胸怀何似  亭台依旧，羡
他烟水全收”，临水悬匾“中流自在”，由当代名家板桥先生手书。
LONG);

  set("outdoors", "/u/swordman");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qigai" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jiedao2",
  "south" : __DIR__"jiedao",
]));
  set("light_up", 1);

  setup();
}
