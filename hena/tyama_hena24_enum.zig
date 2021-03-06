//usr/bin/env zig run "$0" "$@";exit
const std = @import("std");

fn isqrt(n:i64)i64{
    if(n<=0){return 0;}
    if(n<4){return 1;}
    var x:i64=0;
    var y:i64=n;
    while(x!=y and x+1!=y){x=y;y=@divFloor(@divFloor(n,y)+y,2);}
    return x;
}
fn icbrt(n:i64)i64{
    if(n<0){return -icbrt(-n);}
    if(n==0){return 0;}
    if(n<8){return 1;}
    var x:i64=0;
    var y:i64=n;
    while(x!=y and x+1!=y){x=y;y=@divFloor(@divFloor(@divFloor(n,y),y)+y*2,3);}
    return x;
}

fn is_sq(n:i64)bool{
    var x=isqrt(n);
    return x*x==n;
}
fn is_cb(n:i64)bool{
    var x=icbrt(n);
    return x*x*x==n;
}
fn is_multiple(i:i64,n:i64)bool{return @mod(i,n)==0;}
fn is_le(i:i64,n:i64)bool{return i<=n;}

fn generate(val:*i64)void{
    val.* = 1;
    while(true){
        suspend;
        val.* += 1;
    }
}

fn drop_prev(val:*i64,check:fn(i64)bool,prevvalue:*i64,prevframe:anyframe->void)void{
    var a = prevvalue.*;
    resume prevframe;
    var b = prevvalue.*;
    while(true){
        if(!check(b)){val.* = a;suspend;}
        a = b;
        resume prevframe;
        b = prevvalue.*;
    }
}

fn drop_next(val:*i64,check:fn(i64)bool,prevvalue:*i64,prevframe:anyframe->void)void{
    var a = prevvalue.*;
    resume prevframe;
    var b = prevvalue.*;
    val.* = a;
    suspend;
    while(true){
        if(!check(a)){val.* = b;suspend;}
        a = b;
        resume prevframe;
        b = prevvalue.*;
    }
}

fn drop_n(val:*i64,check:fn(i64,i64)bool,n:i64,prevvalue:*i64,prevframe:anyframe->void)void{
    var i:i64 = 0;
    while(true){
        i+=1;
        var a:i64 = prevvalue.*;
        if(!check(i,n)){val.* = a;suspend;}
        resume prevframe;
    }
}

pub fn main()!void{
    var stdin_ = std.io.getStdIn().inStream();
    var stdin = std.io.bufferedInStream(stdin_).inStream();
    var stdout_ = std.io.getStdOut().outStream();
    var stdout = std.io.bufferedOutStream(stdout_).outStream();
    var buf: [99]u8 = undefined;

    while(true){
        if(try stdin.readUntilDelimiterOrEof(buf[0..], '\n')) |user_input|{
            var h = std.AutoHashMap(u8,i64).init(std.heap.page_allocator);
            defer h.deinit();
            _ = try h.put('S',0);
            _ = try h.put('s',0);
            _ = try h.put('C',0);
            _ = try h.put('c',0);
            _ = try h.put('h',0);
            _ = try h.put('2',0);
            _ = try h.put('3',0);
            _ = try h.put('4',0);
            _ = try h.put('5',0);
            _ = try h.put('6',0);
            _ = try h.put('7',0);
            _ = try h.put('8',0);
            _ = try h.put('9',0);

            var len = user_input.len;
            var reslst = try std.heap.page_allocator.alloc(i64,len+1);
            defer std.heap.page_allocator.free(reslst);
            var framelst = try std.heap.page_allocator.alloc(anyframe->void,len+1);
            defer std.heap.page_allocator.free(framelst);
            framelst[0] = &(async generate(&reslst[0]));
            var i:usize=0;
            while(i<len){
                // async frameが行番号か何かで管理されているのか、同じ文字を複数回与えると"resumed a non-suspended function"が発生します。
                // やむを得ず、文字が与えられるたびに行番号を変えてframelstに入れるようにしています。本当にひどい。
                if(user_input[i]=='S'){
                    if(h.get('S').? == 0)framelst[i+1] = &(async drop_next(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('S').? == 1)framelst[i+1] = &(async drop_next(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('S').? == 2)framelst[i+1] = &(async drop_next(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('S').? == 3)framelst[i+1] = &(async drop_next(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('S').? == 4)framelst[i+1] = &(async drop_next(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    _ = try h.put('S',h.get('S').?+1);
                }
                if(user_input[i]=='s'){
                    if(h.get('s').? == 0)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('s').? == 1)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('s').? == 2)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('s').? == 3)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    if(h.get('s').? == 4)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_sq,&reslst[i],framelst[i]));
                    _ = try h.put('s',h.get('s').?+1);
                }
                if(user_input[i]=='C'){
                    if(h.get('C').? == 0)framelst[i+1] = &(async drop_next(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('C').? == 1)framelst[i+1] = &(async drop_next(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('C').? == 2)framelst[i+1] = &(async drop_next(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('C').? == 3)framelst[i+1] = &(async drop_next(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('C').? == 4)framelst[i+1] = &(async drop_next(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    _ = try h.put('C',h.get('C').?+1);
                }
                if(user_input[i]=='c'){
                    if(h.get('c').? == 0)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('c').? == 1)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('c').? == 2)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('c').? == 3)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    if(h.get('c').? == 4)framelst[i+1] = &(async drop_prev(&reslst[i+1],is_cb,&reslst[i],framelst[i]));
                    _ = try h.put('c',h.get('c').?+1);
                }
                if(user_input[i]=='h'){
                    if(h.get('h').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_le,100,&reslst[i],framelst[i]));
                    if(h.get('h').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_le,100,&reslst[i],framelst[i]));
                    if(h.get('h').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_le,100,&reslst[i],framelst[i]));
                    if(h.get('h').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_le,100,&reslst[i],framelst[i]));
                    if(h.get('h').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_le,100,&reslst[i],framelst[i]));
                    _ = try h.put('h',h.get('h').?+1);
                }
                if(user_input[i]=='2'){
                    if(h.get('2').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,2,&reslst[i],framelst[i]));
                    if(h.get('2').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,2,&reslst[i],framelst[i]));
                    if(h.get('2').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,2,&reslst[i],framelst[i]));
                    if(h.get('2').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,2,&reslst[i],framelst[i]));
                    if(h.get('2').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,2,&reslst[i],framelst[i]));
                    _ = try h.put('2',h.get('2').?+1);
                }
                if(user_input[i]=='3'){
                    if(h.get('3').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,3,&reslst[i],framelst[i]));
                    if(h.get('3').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,3,&reslst[i],framelst[i]));
                    if(h.get('3').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,3,&reslst[i],framelst[i]));
                    if(h.get('3').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,3,&reslst[i],framelst[i]));
                    if(h.get('3').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,3,&reslst[i],framelst[i]));
                    _ = try h.put('3',h.get('3').?+1);
                }
                if(user_input[i]=='4'){
                    if(h.get('4').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,4,&reslst[i],framelst[i]));
                    if(h.get('4').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,4,&reslst[i],framelst[i]));
                    if(h.get('4').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,4,&reslst[i],framelst[i]));
                    if(h.get('4').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,4,&reslst[i],framelst[i]));
                    if(h.get('4').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,4,&reslst[i],framelst[i]));
                    _ = try h.put('4',h.get('4').?+1);
                }
                if(user_input[i]=='5'){
                    if(h.get('5').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,5,&reslst[i],framelst[i]));
                    if(h.get('5').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,5,&reslst[i],framelst[i]));
                    if(h.get('5').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,5,&reslst[i],framelst[i]));
                    if(h.get('5').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,5,&reslst[i],framelst[i]));
                    if(h.get('5').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,5,&reslst[i],framelst[i]));
                    _ = try h.put('5',h.get('5').?+1);
                }
                if(user_input[i]=='6'){
                    if(h.get('6').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,6,&reslst[i],framelst[i]));
                    if(h.get('6').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,6,&reslst[i],framelst[i]));
                    if(h.get('6').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,6,&reslst[i],framelst[i]));
                    if(h.get('6').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,6,&reslst[i],framelst[i]));
                    if(h.get('6').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,6,&reslst[i],framelst[i]));
                    _ = try h.put('6',h.get('6').?+1);
                }
                if(user_input[i]=='7'){
                    if(h.get('7').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,7,&reslst[i],framelst[i]));
                    if(h.get('7').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,7,&reslst[i],framelst[i]));
                    if(h.get('7').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,7,&reslst[i],framelst[i]));
                    if(h.get('7').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,7,&reslst[i],framelst[i]));
                    if(h.get('7').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,7,&reslst[i],framelst[i]));
                    _ = try h.put('7',h.get('7').?+1);
                }
                if(user_input[i]=='8'){
                    if(h.get('8').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,8,&reslst[i],framelst[i]));
                    if(h.get('8').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,8,&reslst[i],framelst[i]));
                    if(h.get('8').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,8,&reslst[i],framelst[i]));
                    if(h.get('8').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,8,&reslst[i],framelst[i]));
                    if(h.get('8').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,8,&reslst[i],framelst[i]));
                    _ = try h.put('8',h.get('8').?+1);
                }
                if(user_input[i]=='9'){
                    if(h.get('9').? == 0)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,9,&reslst[i],framelst[i]));
                    if(h.get('9').? == 1)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,9,&reslst[i],framelst[i]));
                    if(h.get('9').? == 2)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,9,&reslst[i],framelst[i]));
                    if(h.get('9').? == 3)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,9,&reslst[i],framelst[i]));
                    if(h.get('9').? == 4)framelst[i+1] = &(async drop_n(&reslst[i+1],is_multiple,9,&reslst[i],framelst[i]));
                    _ = try h.put('9',h.get('9').?+1);
                }
                i+=1;
            }
            i = 0;
            while(i<10){
                if(i>0)try stdout.print(",",.{});
                try stdout.print("{}",.{reslst[len]});
                resume framelst[len];
                i+=1;
            }
            try stdout.print("\n",.{});
            try stdout.context.flush();
        }else{
            break;
        }
    }
}
