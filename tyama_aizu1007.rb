#!/usr/bin/ruby
def Z(a,i)b=[];1.step(i){b<<$x;$x+=1}
b.reverse!if$c>0
$c^=1;a<<b
end
t=0
while(n=gets.to_i)>0
puts"Case #{t+=1}:"
a=[];$x=$c=1
1.step(n){|i|Z(a,i)}
(n-1).step(1,-1){|i|Z(a,i)}
n.times{|i|n.times{|j|printf("%3d",a[i+j].shift)};puts}
end