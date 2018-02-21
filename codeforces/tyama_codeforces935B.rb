#!/usr/bin/ruby
n=gets.to_i
a=[r=0]
gets.chomp.chars{|c|
	a<<a[-1]+(c=='U'?1:-1)
	r+=1 if a[-2]==0&&(a[-3].to_i*a[-1]<0)
}
p r
