#!/usr/bin/ruby
class Fixnum
	def fibo
		return to_enum(:fibo) if !block_given?
		yield 1
		a=1
		b=self
		loop{
			yield b
			a,b=b,a+b
		}
	end
	def dfibo
		h={}
		if false #O(nlogn)
			1.step(self-1){|i|
				a=i.fibo.take_while{|e|e<=self}
				if a.last==self
					a.each{|e|h[e]=1}
				end
			}
		else #O((logn)2)
			1.fibo.take_while{|e|e<self}.each_cons(2){|e,f|
				if (self-e)%f==0
					((self-e)/f).fibo.take_while{|g|g<=self}.each{|g|h[g]=1}
				end
			}
		end
		return h.keys.sort
	end
end
DATA.each{|e|
	a=e.split.map(&:to_i)
	puts "GCFibo( #{a.join(', ')} ) = "+a.map(&:dfibo).reduce(:&).last.to_s
}
__END__
10 14
18 14
73 97
23 25
308 320
6168 9877
18518 19942