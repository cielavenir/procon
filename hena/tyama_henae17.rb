#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde17palin/
#http://qiita.com/Nabetani/items/aa15539c8dc2c610c1a0
def solve(t,b=10)
	return to_enum(:solve,t,b) if !block_given?
	(0...b).each{|i|return if i>t;yield i}
	start=1
	digit=1
	loop{
		start.step(start*b-1){|i|
			s=i.to_s(b)
			n=(s+s.reverse).to_i(b)
			return if n>t
			yield n
		}
		start.step(start*b-1){|i|
			s=i.to_s(b)
			(0...b).each{|mid|
				n=(s+mid.to_s(b)+s.reverse).to_i(b)
				return if n>t
				yield n
			}
		}
		start*=b
		digit+=b
	}
end

while gets
	x,y,b=$_.split(',').map &:to_i
	p solve(y-1,b).to_a.size-solve(x-1,b).to_a.size
	STDOUT.flush
end
