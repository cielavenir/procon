#!/bin/bash
set -eu
read n
while [ $n -ne 0 ]; do
  ma=0;mi=1000;sum=0;i=0
  while [ $i -ne $n ]; do
    read s
    if [ $ma -le $s ]; then ma=$s; fi
    if [ $mi -ge $s ]; then mi=$s; fi
    sum=$((sum + s))
    i=$((i + 1))
  done
  sum=$((sum - ma - $mi))
  n=$((n - 2))
  echo $((sum / n))
  read n
done