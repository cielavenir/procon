#!/usr/bin/ruby
def pan(n)
	m=''
	1.step(9){|i|
		x=m+(n*i).to_s
		if x.length>9 then break end
		m=x
	}
	1.step(9){|i| unless m.index(i.to_s) then return 0 end}
	return m.to_i
end
p 10.step(9999).map{|e|pan(e)}.max