#!/usr/bin/ruby
while s=gets
a,b=s.split.map(&:to_i)
#bまでの奇数の数-(a-1)までの奇数の数が奇数
puts ((((b+1)>>1)-(a>>1))&1)==1?"ODD":"EVEN"
#a%=100;b=b%100+100
#puts a.step(b).reduce(:+)&1==1?"ODD":"EVEN"
end