#!/usr/bin/ruby
require 'prime'
h=Hash.new{|h,k|h[k]=[]}
Prime.each(9999).drop_while{|e|e<1000}.each{|e|h[e.to_s.split('').sort*'']<<e}
h.each_value{|v|
	if v.size<3 then next end
	0.step(v.size-3){|i|
		(i+1).step(v.size-2){|j|
			(j+1).step(v.size-1){|k|
				if v[k]-v[j]==v[j]-v[i] then puts [v[i],v[j],v[k]]*'' end
			}
		}
	}
}