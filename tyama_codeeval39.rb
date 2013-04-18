#!/usr/bin/ruby
def seq(n) n.to_s.chars.reduce(0){|s,e|s+=e.to_i**2} end
a=Array.new(200,-1)
a[1]=1
2.step(199){|i|
	if a[i]>-1 then next end
	j=i
	b=[]
	while j!=1 && !b.include?(j)
		b<<j
		j=seq(j)
	end
	b.each{|e|a[e]=(j==1?1:0)}
}
while s=gets do n=s.to_i;n=seq(n) while n>199;p a[n] end