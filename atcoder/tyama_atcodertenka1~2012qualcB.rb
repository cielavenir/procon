#!/usr/bin/ruby
a=gets.chomp.gsub('10','T').split('')
b=[]
0.step(a.size-1,2){|i|b<<a[i]+a[i+1]}
i=0
h={}
loop{
	h[b[i]]=true
	if h['ST']&&h['SJ']&&h['SQ']&&h['SK']&&h['SA'] then suit='S';break end
	if h['HT']&&h['HJ']&&h['HQ']&&h['HK']&&h['HA'] then suit='H';break end
	if h['DT']&&h['DJ']&&h['DQ']&&h['DK']&&h['DA'] then suit='D';break end
	if h['CT']&&h['CJ']&&h['CQ']&&h['CK']&&h['CA'] then suit='C';break end
	i+=1
}
if i==4 then p 0 else
i.times{|j|
	if b[j][0,1]!=suit||"23456789".index(b[j][1,1]) then print b[j].gsub('T','10') end
}
puts
end