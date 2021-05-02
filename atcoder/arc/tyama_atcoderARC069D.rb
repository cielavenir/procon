#!/usr/bin/ruby
n,s=`dd`.split;n=n.to_i
%w(SS SW WS WW).find{|a|
	2.upto(n+1){|i|a[i]=(a[i-1]==?W)^(a[i-2]==?W)^(s[~-i%n]==?o)??S:?W}
	a[0,2]==a[n,2]&&$><<a[0..-3]*''
}||p(-1)
