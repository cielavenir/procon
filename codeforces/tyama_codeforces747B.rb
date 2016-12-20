#!/usr/bin/ruby
n=gets.to_i
s=gets.chomp
h=Hash.new 0
g=Hash.new n/4
s.each_char{|c|h[c]+=1 if c!='?'}
if n%4>0||h.any?{|k,v|g[k]-=v;v>n/4}
	puts '==='
	exit
end
s.each_char{|c|
	if c!='?'
		print c
	else
		x='ATGC'.chars.find{|x|g[x]>0}
		g[x]-=1
		print x
	end
}
puts