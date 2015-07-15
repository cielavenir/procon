#!/usr/bin/ruby
h=Hash.new{|h,k|h[k]=[]}
gets
gets.split.each.with_index(1){|e,i|
	h[e.to_i]<<i
}
siz=h.map{|k,v|v.size}.max
a=h.select{|k,v|v.size==siz}.min_by{|k,v|v.last-v.first}[1]
puts [a.first,a.last]*' '