#!/usr/bin/ruby
class Fixnum
	def /(o)
		fdiv(o).truncate
	end
end
n,x,*a=`dd`.split.map(&:to_i)
mi=ma=x
a.each{|e|
	mi,ma=[mi,ma].product(['+','-','*',e==0?'+':'/']).map{|v,o|
		v.send(o,e)
	}.minmax
}
p ma
