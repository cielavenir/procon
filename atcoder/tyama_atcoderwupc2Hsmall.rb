#!/usr/bin/ruby
n,m=gets.split.map(&:to_i)
if n>8||m>8 then exit 1 end
a=m.times.map{gets.split.map(&:to_i)}
r=0
1.step(m){|i|
	a.combination(i){|b|
		z=Array.new(n,0)
		b.each{|c|
			(c[0]-1).step(c[1]-1){|x|
				z[x]+=1
			}
		}
		r+=1 if z.all?{|e|e>1}
	}
}
p r%1000000007