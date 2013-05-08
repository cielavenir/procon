#!/usr/bin/ruby
str=gets.chomp
len=str.size
str=str[str.index('o')..-1]
idx=str.size.times.select{|i|str[i..i]=='o'}
a=Array.new(len)
p len.times.count{|i|
	if !a[i]
		idx.each{|j|a[i+j]=1}
		1
	else
		nil
	end
}