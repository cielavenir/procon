#!/usr/bin/ruby
n=gets.to_i+1
q=[*1..x=n.to_s(2).size-1]
n-=1<<x
x.downto(0){|i|n>=1<<i&&(q.insert(i,x+=1);n-=1<<i)}
q+=[*1..q.size]
p q.size,*q
#puts q*' '
