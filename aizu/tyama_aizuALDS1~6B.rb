#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i)
x=a[a.size-1]
i=-1
0.step(a.size-2){|j|
	if a[j]<=x
		i=i+1
		a[i],a[j]=a[j],a[i]
	end
}
a[i+1],a[a.size-1]=a[a.size-1],a[i+1]
puts a.each_with_index.map{|e,z|(z==i+1?'[%d]':'%d')%e}*' '