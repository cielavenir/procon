#!/usr/bin/ruby
table={"A"=>71.03711,"C"=>103.00919,"D"=>115.02694,"E"=>129.04259,"F"=>147.06841,"G"=>57.02146,"H"=>137.05891,"I"=>113.08406,"K"=>128.09496,"L"=>113.08406,"M"=>131.04049,"N"=>114.04293,"P"=>97.05276,"Q"=>128.05858,"R"=>156.10111,"S"=>87.03203,"T"=>101.04768,"V"=>99.06841,"W"=>186.07931,"Y"=>163.06333}
a=gets.to_i.times.map{gets.chomp}
b=[]
while gets
b<<$_.to_f
end
puts a.map{|e|
	x=[];y=[]
	e.length.times.each{|i|
		x[i]=(x[i-1]||0)+table[e[i]]
		y[i]=(y[i-1]||0)+table[e.reverse[i]]
	}
	h=Hash.new(0)
	(x+y).each{|f|
		b.each{|g|
			h[sprintf("%f",f-g)]+=1
		}
	}
	[h.values.max,e]
}.max*"\n"