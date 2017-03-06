#!/usr/bin/ruby
n,k=gets.split.map &:to_i
a=gets.split.map &:to_i
s=n.times.map{gets.chomp}
t=[]
#aがソートされてないなんて聞いてないよ(sample is crappy!) ToT
a.sort_by(&:-@).each{|i|t<<s.delete_at(i-1)}
r=t[0]
t.map{|e|l=[e.size,r.size].min;r=r[0,(0...l).find{|i|e[i]!=r[i]}||l]}
t=(0..r.size).find{|i|s.none?{|e|e.start_with?(r[0,i])}}
puts t ?r[0,t]:-1
