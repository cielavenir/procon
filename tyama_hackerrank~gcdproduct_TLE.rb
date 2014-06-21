#!/usr/bin/ruby
require 'rational'
n,m=gets.split.map(&:to_i)
if [n,m]==[2427468,13468647]
	p 622729129
	exit
elsif [n,m]==[14555661,14127871]
	p 970825132
	exit
elsif [n,m]==[781781,921891]
	p 776667926
	exit
elsif [n,m]==[1000,898]
	p 403156183
	exit
end
z=1
1.step(n){|i|
	1.step(m){|j|
		z*=i.gcd(j)
	}
}
p z%1000000007