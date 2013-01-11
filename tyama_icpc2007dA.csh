#!/bin/csh -f
set n="$<"
while ($n != 0)
  set ma=0;set mi=1000;set sum=0;set i=0
  while ($i != $n)
    set s="$<"
    if ($ma < $s) set ma=$s
    if ($mi > $s) set mi=$s
    set sum=`expr $sum + $s`
    set i=`expr $i + 1`
  end
  set sum=`expr $sum - $ma - $mi`
  set n=`expr $n - 2`
  expr $sum / $n
  set n="$<"
end