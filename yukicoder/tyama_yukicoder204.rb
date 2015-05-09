#!/usr/bin/ruby
n=gets.to_i
a=('x'*14+$<.map(&:strip).join+'x'*14).chars.chunk{|e|e}.to_a
r=0
a.size.times{|i|
	if a[i][0]=='o'
		r=[r,a[i][1].size].max
	elsif a[i][1].size>n
		r=[r,(i==0 ? 0 : a[i-1][1].size)+n,(i==a.size-1 ? 0 : a[i+1][1].size)+n].max
	else
		r=[r,(i==0 ? 0 : a[i-1][1].size)+(i==a.size-1 ? 0 : a[i+1][1].size)+a[i][1].size].max
	end
}
p r