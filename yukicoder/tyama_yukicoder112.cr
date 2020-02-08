#!/usr/bin/env crystal
n=gets.not_nil!.to_i
a=gets.not_nil!.split.map(&.to_i)
#x+y=n-1
#2x+4y=a[0]
y=(a[0] - 2*(n-1))//2
x=n-1-y
#decide 0
if a.all?{|e|e==a[0]}
	if x>0
		puts "#{x+1} 0"
	else
		puts "0 #{y+1}"
	end
else
	if a[0]==a.max
		puts "#{x+1} #{y}"
	else
		puts "#{x} #{y+1}"
	end
end
