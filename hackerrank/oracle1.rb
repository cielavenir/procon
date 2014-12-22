#!/usr/bin/ruby
n,p,l,k,utmost=gets.split.map(&:to_i)
cnt=gets.to_i
raise if n%2==1
a=$<.map(&:chomp)
asked=[0]
maj=Array.new(k){[]};maj[0]=[0]
a.each{|e|
	b=e.split
	if b[2]=='YES'
		maj[0]<<b[1].to_i
	else
		maj[1]<<b[1].to_i
	end
	asked<<b[1].to_i
}
if r=maj.find{|e|e.size>=n/2}
	puts r.first
else
	puts "0 "+(n.times.to_a-asked).sample.to_s
end