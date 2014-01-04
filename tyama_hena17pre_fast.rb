#!/usr/bin/env ruby
#http://qiita.com/Nabetani/items/dabe8ec57e0313229552
#http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
STDOUT.sync=true
class Integer
	def palindrome?(b)
		n0=self
		n1=0
		while n0>0
			n1=n1*b+n0%b
			n0/=b
		end
		n1==self
	end
end
while gets
	n=$_.to_i
	if n<3 then puts '-';next end
	result=[]
	Math.sqrt(n-1).to_i.downto(2).each{|i|
		result.push((n-1)/i) if n.palindrome?((n-1)/i)
		result.unshift(i) if (n-1)/i!=i&&n.palindrome?(i) # n-1 might be a square number
	}
	puts (result+[n-1])*','
end