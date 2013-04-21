#!/usr/bin/ruby
#wget -O - http://projecteuler.net/project/words.txt
require 'json'
a=JSON.parse('['+gets.chomp+']')
h=Hash.new{|h,k|h[k]=[]}
$sq=(1..40000).map{|e|(e**2).to_s}
a.each{|e|h[e.chars.sort*'']<<e}
m=0
h.each{|k,v|
	next if v.size<2
	0.step(v.size-2){|i|
		(i+1).step(v.size-1){|j|
			sq=$sq.select{|e|e.size==v[i].size}
			sq.each{|e|
				map1={};map2={}
				if v[i].size.times{|k|
					#break if map1[v[i][k..k]]&&map1[v[i][k..k]]!=e[k..k]
					break if map2[e[k..k]]&&map2[e[k..k]]!=v[i][k..k]
					#map1[v[i][k..k]]=e[k..k]
					map2[e[k..k]]=v[i][k..k]
				}
					vjx=v[j].dup
					#map1.each{|k,v|vjx.gsub!(k,v)}
					map2.each{|k,v|vjx.gsub!(v,k)}
					num=sq.find{|f|f==vjx}
					if num
						#p [e,num]
						m=[m,num.to_i,e.to_i].max
					end
				end
			}
		}
	}
}
p m