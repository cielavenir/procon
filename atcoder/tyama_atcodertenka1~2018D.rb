#!/usr/bin/ruby
d=1+8*gets.to_i
q=Math.sqrt(d).to_i
if q**2!=d
	puts :No;exit
end
k=(-1+q)/2
puts :Yes,k+1
puts [k,*k.times.map{|i|-~i*(i+2)/2}]*' '
k.times{|i|
	a=[k,i*-~i/2+1]
	i.times{|j|a<<a[-1]+1}
	(i+1...k).each{|j|a<<a[-1]+j}
	puts a*' '
}
