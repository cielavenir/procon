#!/usr/bin/ruby
t,*s=gets.chomp.split(?T,-1).map(&:size)
k=gets.split.map &:to_i
k[0]-=t
s,*t=s.each_slice(2).to_a
s=(s||[]).zip(*t).map{|e|e.compact.sort_by &:-@}
puts 2.times.all?{|i|(s[i^1]||[]).map{|e|k[i]+=e*(k[i]<0?1:-1)};k[i]==0}?:Yes: :No
