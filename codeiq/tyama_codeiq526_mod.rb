#!/usr/bin/ruby
require 'rational'
min=9999999
r=[]
# mを自然数、nをm未満の自然数とするとき、ピタゴラス数は、
# m*m-n*n,2*m*n,m*m+n*n
# で列挙することができる(ただしこの3数は互いに素である必要がある)
(1..1/0.0).each{|m|
	if m*m-(m-1)*(m-1)>min && 2*m*1>min #これ以上aは小さくし得ない
		puts r*',' # 763,291084,291085
		exit
	end
	(1-m%2).step(m-1,2){|n|
		next if m.gcd(n)>1
		a=m*m-n*n
		b=2*m*n
		c=m*m+n*n
		#if (a.to_s+b.to_s+c.to_s).split('').sort.join.squeeze=='0123456789'
		if ([*'0'..'9']-[a,b,c].join.each_char.to_a).empty?
			if [a,b].min<min
				min=[a,b].min
				r=[min,[a,b].max,c]
				#puts r*','
			end
		end
	}
}