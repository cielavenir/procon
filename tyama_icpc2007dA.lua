#!/usr/bin/lua --
while 1 do
  ma=0
  mi=1000
  sum=0
  n=io.read("*n")
  i=0
  if n==0 then break end
  repeat
    s=io.read("*n")
    if ma < s then ma = s end
    if mi > s then mi = s end
    sum = sum + s
    i = i + 1;
  until i==n
  print(math.floor((sum - ma - mi) / (n - 2)))
end