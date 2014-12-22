#!/usr/bin/ruby
n,p,l,k,utmost=gets.split.map(&:to_i)
cnt=gets.to_i
raise if n%2==1
a=$<.map(&:chomp)
maj=Array.new(k){[]};maj[0]=[0]
a.each{|e|
	b=e.split
	if b[2]=='YES'
		maj[0]<<b[1].to_i
	else
		maj[1]<<b[1].to_i
	end
}
if r=maj.find{|e|e.size>=n-1}
	puts r.first
else
	puts "0 "+(cnt/2+1).to_s
end