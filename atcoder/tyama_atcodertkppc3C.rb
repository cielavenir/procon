#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
t=Rational 1
head=tail=0
while tail<a.size
t*=a[tail];tail+=1
(t/=a[head];head+=1)while head<tail-1&&t>k
(puts 'Yay!';exit)if t==k
end
puts ':('
