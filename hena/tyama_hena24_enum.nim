#[
/usr/bin/env nim c --nimcache:$HOME/.nimcache --opt:speed --run $0 $@;exit
#]#
proc isqrt(n:int):int =
 if n<=0: return 0
 if n<4: return 1
 var x=0
 var y=n
 while x!=y and x+1!=y:
  x=y
  y=(n div y+y) div 2
 return x

proc icbrt(n:int):int =
 if n<0: return icbrt(-n)
 if n==0: return 0
 if n<8: return 1
 var x=0
 var y=n
 while x!=y and x+1!=y:
  x=y
  y=(n div y div y+y*2) div 3
 return x

proc generate():iterator:int =
 return iterator:int =
  var i=1
  while true:
   yield i
   i+=1

proc drop_prev(check:proc(x:int):bool,prev:iterator:int):iterator:int =
 return iterator:int =
  var a=prev()
  var b=prev()
  while true:
   if not check(b): yield a
   a=b
   b=prev()

proc drop_next(check:proc(x:int):bool,prev:iterator:int):iterator:int =
 return iterator:int =
  var a=prev()
  var b=prev()
  yield a
  while true:
   if not check(a): yield b
   a=b
   b=prev()

proc drop_n(check:proc(x:int,y:int):bool,n:int,prev:iterator:int):iterator:int =
 return iterator:int =
  var i=0
  while true:
   i+=1
   var a=prev()
   if not check(i,n): yield a

proc is_sq(n:int):bool =
 var x=isqrt(n)
 return x*x==n

proc is_cb(n:int):bool =
 var x=icbrt(n)
 return x*x*x==n

proc is_multiple(i:int,n:int):bool = i mod n==0
proc is_le(i:int,n:int):bool = i<=n

import tables
var f={
 'S':proc(e:iterator:int):iterator:int = drop_next(is_sq,e),
 's':proc(e:iterator:int):iterator:int = drop_prev(is_sq,e),
 'C':proc(e:iterator:int):iterator:int = drop_next(is_cb,e),
 'c':proc(e:iterator:int):iterator:int = drop_prev(is_cb,e),
 'h':proc(e:iterator:int):iterator:int = drop_n(is_le,100,e),
 '2':proc(e:iterator:int):iterator:int = drop_n(is_multiple,2,e),
 '3':proc(e:iterator:int):iterator:int = drop_n(is_multiple,3,e),
 '4':proc(e:iterator:int):iterator:int = drop_n(is_multiple,4,e),
 '5':proc(e:iterator:int):iterator:int = drop_n(is_multiple,5,e),
 '6':proc(e:iterator:int):iterator:int = drop_n(is_multiple,6,e),
 '7':proc(e:iterator:int):iterator:int = drop_n(is_multiple,7,e),
 '8':proc(e:iterator:int):iterator:int = drop_n(is_multiple,8,e),
 '9':proc(e:iterator:int):iterator:int = drop_n(is_multiple,9,e),
}.toTable()
## var handling is strict like Rust ##

import strutils
var s=""
while readLine(stdin,s):
 var z=generate()
 for c in s.strip():
  z=f[c](z)
 for i in 0..9:
  if i>0: write(stdout,',')
  write(stdout,z())
 writeLine(stdout,"")
 flushFile(stdout)
