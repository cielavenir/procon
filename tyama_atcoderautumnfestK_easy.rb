#!/usr/bin/env ruby
STDOUT.sync=true
c=Array.new(9)

9.times{|i|
	a=[*0..9]
	a.delete(i)
	puts "? #{(i.to_s)*9} "+(0..7).map{|j|a.rotate(j)*''}*' '
	a=gets.split.map(&:to_i).each_slice(2).map{|e|e[0]+e[1]}.sort
	c[i]=a[0]==a[1]?a[8]:a[0]
}

c.push(9-c.reduce(:+))
for n in 0..9 do break if c[n]==0 end

s="000000000"
10.times{|i|
	next if i==n
	x=(i+1)%10
	x=(x+1)%10 if x==n
	puts "? #{(i.to_s)*8+(x.to_s)*1} "+(1..8).map{|j|(i.to_s)*j+(n.to_s)*(9-j)}*' '
	a=gets.split.map(&:to_i).each_slice(2).map{|e|e[0]}.sort
	a.pop
	a.push(c[i]).unshift(0)
	9.times{|j|s[j]=i.to_s if a[j]<a[j+1]}
}

puts "! "+s