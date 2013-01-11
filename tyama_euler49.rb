#!/usr/bin/ruby
require 'prime'
h=Hash.new{|h,k|h[k]=[]}
Prime.each(9999).drop_while{|e|e<1000}.map{|e|h[e.to_s.split('').sort*''].push(e)}
h.each_value{|v|
	if v.length<3 then next end
	0.step(v.length-3){|i|
		(i+1).step(v.length-2){|j|
			(j+1).step(v.length-1){|k|
				if v[k]-v[j]==v[j]-v[i] then puts [v[i],v[j],v[k]]*'' end
			}
		}
	}
}