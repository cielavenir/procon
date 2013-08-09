#!/usr/bin/ruby
cur=0
result=[]
str='GAGCCAGCGATA'
str.chars.each{|e|
	if e=='G'
		cur+=1
	elsif e=='C'
		cur-=1
	end
	result<<cur
}
puts result.map{|e|e>0 ? '+'+e.to_s : e.to_s}*', '