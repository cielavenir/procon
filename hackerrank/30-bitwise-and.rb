#!/usr/bin/ruby
gets.to_i.times{
	n,k=gets.split.map(&:to_i)
	#order: O(klogk)
	p (k-1).downto(0).find{|a|
		z=a.to_s(2).chars
		z.size.times.any?{|i|z[i]=='0'&&(z[0,i]+['1']+z[i+1..-1]).join.to_i(2)<=n}||(['1']+z).join.to_i(2)<=n
	}
}