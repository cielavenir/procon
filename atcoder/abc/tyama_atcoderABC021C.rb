#!/usr/bin/ruby
n=gets.to_i
s,g=gets.split.map(&:to_i)
h=Hash.new{|h,k|h[k]=[]}
gets.to_i.times{|i|
	a,b=gets.split.map(&:to_i)
	h[a]<<b
	h[b]<<a
}
q=[s]
depth={s=>1}
sum=Hash.new(0)
sum[s]=1
while !q.empty?
	cur=q.shift
	h[cur].each{|e|
		if !depth.has_key?(e)
			depth[e]=depth[cur]+1
			q<<e
		end
		if depth[e]==depth[cur]+1
			sum[e]+=sum[cur]
		end
	}
end
p sum[g]%1000000007