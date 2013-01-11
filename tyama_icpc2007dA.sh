#!/bin/sh
read n
while [ $n -ne 0 ]; do
  ma=0;mi=1000;sum=0;i=0
  while [ $i -ne $n ]; do
    read s
    if [ $ma -le $s ]; then ma=$s; fi
    if [ $mi -ge $s ]; then mi=$s; fi
    sum=`expr $sum + $s`
    i=`expr $i + 1`
  done
  sum=`expr $sum - $ma - $mi`
  n=`expr $n - 2`
  expr $sum / $n
  read n
done