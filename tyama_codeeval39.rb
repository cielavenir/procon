#!/usr/bin/ruby
def seq(n) n.to_s.split(//).map{|e|e.to_i**2}.reduce(:+) end
a=Array.new(200,-1)
a[1]=1
2.step(199){|i|
	if a[i]>-1 then next end
	j=i
	b=[]
	while j!=1 && !b.include?(j)
		b.push(j)
		j=seq(j)
	end
	b.each{|e|a[e]=(j==1?1:0)}
}
while s=gets do n=s.to_i;while n>199 do n=seq(n) end;puts a[n] end