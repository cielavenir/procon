#!/usr/bin/ruby
a=[]
while gets
a<<$_.chomp.split('')
end
s=''
a=a.transpose
a=a.map{|e|
	b='ACGT'.chars.map{|e0|[e.count{|e1|e0==e1},e0]}
	s<<b.max[1]
	b
}.transpose
puts s
a.each{|e|
	print e[0][1]+': '
	puts e.map{|f|f[0]}.join' '
}