#!/usr/bin/ruby
h=Hash.new{|h,k|h[k]=[]}
(1..gets.to_i).each{|i|
	n=i
	unless n.to_s!=n.to_s.reverse && 60.times.all?{
		n+=n.to_s.reverse.to_i;n.to_s!=n.to_s.reverse
	}
		h[n]<<i
	end
}
r=h.sort_by{|k,v|-v.size}[0]
puts r[0].to_s+' '+r[1].size.to_s