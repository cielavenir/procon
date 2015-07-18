#!/usr/bin/env nim
import strutils
while true:
 var NKM=readLine(stdin).split()
 var n=parseInt(NKM[0])
 var k=parseInt(NKM[1])
 var m=parseInt(NKM[2])
 if n==0: break
 var r=0
 for i in 1..n-1: r=(r+k) mod i
 echo((r+m) mod n+1)