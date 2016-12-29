#!/usr/bin/ruby
m=gets.to_i.times.map{gets.split.map(&:to_f)}
$>.<<("? 0 0\n? 1 1\n!\n").flush
dx,dy=gets.split.map(&:to_f)
cms,cps=gets.split.map(&:to_f)
cms-=dx
cps-=dy
c=(cms+cps)/2
s=(cps-cms)/2
m.each{|x,y|puts '%f %f'%[x*c-y*s+dx,x*s+y*c+dy]}
