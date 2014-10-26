#!/usr/bin/ruby
require 'prime'
N,K=gets.split.map(&:to_i)
h=Hash.new{|h,k|h[k]=[]}
Prime.each(999999).drop_while{|e|e<1000}.each{|e|h[e.to_s.split('').sort*'']<<e}
r=[]
h.each_value{|v|
	if v.size<K then next end
	0.step(v.size-3){|i|
		break if v[i]>=N
		(i+1).step(v.size-2){|j|
			(j+1).step(v.size-1){|k|
				if K==3
					if v[k]-v[j]==v[j]-v[i] then r<<[v[i],v[j],v[k]] end
				else
					(k+1).step(v.size-1){|l|
						if v[l]-v[k]==v[k]-v[j] && v[k]-v[j]==v[j]-v[i]
							r<<[v[i],v[j],v[k],v[l]]
						end
					}
				end
			}
		}
	}
}
puts r.sort.map(&:join)
__END__
10000 3