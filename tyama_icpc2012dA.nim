#[
/usr/bin/env nim c --nimcache:$HOME/.nimcache --opt:speed --run $0 $@;exit
#]#
import strutils
var n=parseInt(readLine(stdin))
for i in 1..n:
 var YMD=readLine(stdin).split()
 var y=parseInt(YMD[0])-1
 var m=parseInt(YMD[1])-1
 var d=parseInt(YMD[2])
 var x=0
 if y mod 3<2:
  x=m div 2
 echo(196471-y*195-y div 3*5-m*20+x-d)
