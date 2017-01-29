#[
/usr/bin/env nim c --nimcache:$HOME/.nimcache --opt:speed --run $0 $@;exit
#]#
import strutils,math
proc scanf(formatstr: cstring){.header:"<stdio.h>",varargs.}
proc printf(formatstr: cstring){.header:"<stdio.h>",varargs.}

var T=0
#T=parseInt(readLine(stdin))
scanf("%d",T.addr)
for i in 1..T:
 var a=0.int64
 var b=0.int64
 var c=0.int64
 #var ABC=readLine(stdin).split()
 #a=parseInt(ABC[0]).int64
 #b=parseInt(ABC[1]).int64
 #c=parseInt(ABC[2]).int64
 scanf("%lld%lld%lld",a.addr,b.addr,c.addr)
 if a==0:
  if b==0:
   #echo(if c!=0: "0" else: "3")
   printf(if c!=0: "0\n" else: "3\n")
  else:
   #echo("1 "&(-c.float64/b.float64).formatFloat(ffDecimal,12))
   printf("1 %.12f\n",-c.float64/b.float64)
 else:
  if a<0:
   a = -a
   b = -b
   c = -c
  var d=b.float64*b.float64-4.0*a.float64*c.float64
  if d.abs<1e-9:
   #echo("1 "&(-b.float64/2.0/a.float64).formatFloat(ffDecimal,12))
   printf("1 %.12f\n",-b.float64/2.0/a.float64)
  elif d<0:
   #echo("0")
   printf("0\n")
  else:
   # acknowledgement: http://tricky.contest.atcoder.jp/submissions/120839
   var x=0.0
   var y=0.0
   if b>0:
    x = (-b.float64-sqrt(d))/2/a.float64
    y = c.float64/a.float64/x
   else:
    y = (-b.float64+sqrt(d))/2/a.float64
    x = c.float64/a.float64/y
   #echo("2 "&x.formatFloat(ffDecimal,12)&" "&y.formatFloat(ffDecimal,12))
   printf("2 %.12f %.12f\n",x,y)
