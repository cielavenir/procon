#!/usr/bin/ruby
m=$<.map{|e|e.split.map{|f|f.split(',').map(&:to_i)}}
s=m.size*m[0].size
h=Hash.new(0)
m.each{|e|e.each{|f|h[f.reduce(:+)/10]+=1}}
r=h.values.max
q=r.to_f/s
if q<0.05||0.95<q
	puts :box
else
	puts :triangle
end
