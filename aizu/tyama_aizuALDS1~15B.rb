#!/usr/bin/ruby
N,o=gets.split.map &:to_i
r=0
N.times.map{gets.split.map &:to_i}.sort_by{|v,w|-Rational(v,w)}.each{|v,w|
k=[o,w].min
r+=v/w.to_f*k
o-=k
}
p r
