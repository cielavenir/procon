#!/usr/bin/ruby
n,k=gets.split.map &:to_i
n-=r=u=1
loop{
x=(u+k-1)/k
n-=x
u+=x
n<0&&break
r+=1
}
p r
