#!/usr/bin/ruby
n=gets.to_i
a=gets.split.map &:to_f
q=a.shift
t=[1-q,q]
a.each.with_index(2){|e,i|
x=[]
x[0]=t[0]*(1-e)
(1...i).each{|j|x[j]=t[j-1]*e+t[j]*(1-e)}
x[i]=t[i-1]*e
t=x
}
p t[n/2+1..-1].reduce(:+)
