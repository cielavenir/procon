#!/usr/bin/ruby
gets
h=gets.split.map(&:to_i).each_with_index.group_by{|e,i|e}
h.default=[]
a=(1..3).map{|e|h[e].map{|_|_.last+1}}
siz=a.map(&:size).min
p siz
siz.times{|i|puts a.map{|e|e[i]}*' '}