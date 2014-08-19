#!/usr/bin/ruby
n=gets.to_i
a=$<.each_with_index.map{|e,i|[e.to_i,i]}.sort.reverse
rank=a[0][2]=1
x=1
1.step(n-1){|i|
	if a[i-1][0]>a[i][0]
		rank+=x
		x=1
	else
		x+=1
	end
	a[i][2]=rank
}
puts a.sort_by{|e|e[1]}.map{|e|e[2]}