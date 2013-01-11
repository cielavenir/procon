#!/usr/bin/env io
f := File standardInput
while(1,
  ma := 0
  mi := 1000
  sum := 0
  n := doString(f readLine)
  if(n == 0, break)
  for(i,1,n,
    s := doString(f readLine)
    if(ma < s, ma := s)
    if(mi > s, mi := s)
    sum := sum + s
  )
  ( (sum - ma - mi) / (n - 2) ) floor println
)