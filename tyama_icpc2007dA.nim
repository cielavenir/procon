#[
/usr/bin/env nim c --nimcache:$HOME/.nimcache --opt:speed --run $0 $@;exit
#]#
import strutils
while true:
 var n=parseInt(readLine(stdin))
 if n==0: break
 var s=0
 var mi=1000
 var ma=0
 for i in 1..n:
  var x=parseInt(readLine(stdin))
  if x<mi: mi=x
  if x>ma: ma=x
  s=s+x
 echo((s-ma-mi) div (n-2))
