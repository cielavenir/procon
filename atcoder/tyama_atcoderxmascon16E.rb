#!/usr/bin/ruby
200.times{
m=(r=0..29).map{gets.split.map &:to_i}
q=->a{m.transpose.map{|e|a.group_by{|i|e[i]}.max_by{|k,v|v.size}[0]}}
k=q[r]
puts q[r.sort_by{|i|-m[i].zip(k).count{|x,y|x==y}}[0,10]]*' '
}
#Ruby 2.2: puts q[r.max_by(10){|i|m[i].zip(k).count{|x,y|x==y}}]*' '
