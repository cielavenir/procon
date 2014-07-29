#!/usr/bin/ruby
N=4
h=Hash.new(0)
(1<<(N*N)).times.each{|i|
	a=(N*N).times.map{|j|(i&(1<<j))>0 ? 'o' : 'x'}.each_slice(N).to_a
	h[ [a,a.transpose].map{|_a|_a.map{|e|e.count('o')}} ]+=1
}
p h.count{|k,v|v==1} # 6902