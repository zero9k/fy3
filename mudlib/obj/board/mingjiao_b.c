// /clone/board/baituo_b.c

inherit BULLETIN_BOARD;

void create()
{
      set_name("明教弟子留言板",({"board"}) )
;
      set("location","/d/mingjiao/dadian")
;
      set("board_id","mingjiao_b")
;
    set("long","这是一个供明教弟子交流的留言板。\n")
;
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
