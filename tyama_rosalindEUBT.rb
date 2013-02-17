#!/usr/bin/ruby
def x(a)
	return ["(#{a[0]},#{a[1]})"] if a.length==2
	return [a[0]] if a.length==1
	r=[]
	1.step(a.length/2){|i|
		a.combination(i){|b|
			d=x(b)
			e=x(a-b)
			e.each{|e0|
				d.each{|d0|
					r<<"(#{e0},#{d0})" if e0<d0
				}
			}
		}
	}
	r
end
a=gets.chomp.split
s=a.shift
x(a).each{|e|
	puts "(#{e})#{s};"
}