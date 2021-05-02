#!/usr/bin/ruby
n,k,*a=`dd`.split.map &:to_i
a.sort!
p (0...n).bsearch{|unneeded|
	dp=[1]+[0]*k
	n.times{|i|
		next if i==unneeded
		k.downto(a[i]){|j|
			dp[j]+=dp[j-a[i]]
		}
	}
	([k-a[unneeded],0].max...k).any?{|j|dp[j]>0}
}||n
