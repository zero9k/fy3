inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string objname, func, param, euid;
        object obj;
        mixed *args, result;
        int i;

        if( arg ) {
                if( sscanf(arg, "-%s %s", euid, arg)==2 ) {
                        if( (string)SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("你不能设定自己的 euid。\n");
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("指令格式：callme me-><函数>( <参数>, ... )\n");
        } else
                return notify_fail("指令格式：callme me-><函数>( <参数>, ... )\n");

        if(objname=="me")
                obj = me;
        else 
                return notify_fail("你只能修改自己的数据。\n");

        if( userp(obj) )
        {
                if( obj != me ) log_file("static/CALL_PLAYER",
                        sprintf("%s(%s) call %s(%s)->%s(%s) on %s\n",
                        me->name(1), geteuid(me), obj->name(1), geteuid(obj), func, param,
                        ctime(time()) ) );
        } 
        else 
                if( !master()->valid_write( base_name(obj), me, "set" ) )
                        return notify_fail("你没有直接呼叫这个物件的函数的权力。\n");

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}

