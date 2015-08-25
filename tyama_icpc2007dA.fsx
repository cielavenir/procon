//usr/bin/env fsharpi $0 $@;exit
open System;;

let rec sum (n,k,ma,mi,s,x) =
  let ma = if ma<x then x else ma in
    let mi = if mi>x then x else mi in
      if k=0 then (s+x-ma-mi)/(n-2) else sum(n,k-1,ma,mi,s+x,Console.ReadLine()|>int);;

while true do
  let n = Console.ReadLine()|>int in
    if n=0 then exit(0) else Console.WriteLine(sum(n,n-1,0,1000,0,Console.ReadLine()|>int)) done;;