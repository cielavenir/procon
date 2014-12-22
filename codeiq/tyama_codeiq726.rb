#!/usr/bin/env ruby
class Integer
	def seven?(f=false)
		raise if self<0
		return f if self==0
		return (self/10).seven?(true) if self%10==0 #先頭桁は0にはなり得ないので手抜き
		return (self/10).seven?(f) if self%10==7
		return false
	end
=begin
	def seven?
		raise if self<0
		return true if self==0
		return false if self%10!=0&&self%10!=7
		(self/10).seven?
	end
=end
	def pan?
		base=10
		n0=self
		n1=0
		while n0>0
			n1=n1*base+n0%base
			n0/=base
		end
		n1==self
	end
end

(1..50).each{|i|
	next if i%2==0||i%5==0 # 「偶数または5の倍数」の倍数の末尾が7になることはないので、回文数には成り得ない
	(1..1/0.0).each{|j|
		if (i*j).seven?
			if (i*j).pan?
				#puts "#{i} * #{j} = #{i*j}"
				print "#{i},"
			end
			break
		end
	}
}
puts