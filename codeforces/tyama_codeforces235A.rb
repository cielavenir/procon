#!/usr/bin/ruby
n=gets.to_i
a=n
b=[1,n-1].max
c=[1,n%2>0 ? n-2 : n-3].max
r=a.lcm(b).lcm(c)
r=[r,(a-1).lcm(b-1).lcm(c)].max if n%2==0&&n%3==0
p r