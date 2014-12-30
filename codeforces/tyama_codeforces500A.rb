#!/usr/bin/env ruby
n,t=gets.split.map(&:to_i)
a=gets.split.map(&:to_i)
cur=0
while cur+1<t
	cur+=a[cur]
end
puts cur+1==t ? :YES : :NO