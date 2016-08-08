#!/usr/bin/ruby
#解法の検証はこれでお許し下さい…
N,A,B,W,*D=`dd`.split.map(&:to_i)
D<<0
R=[W]
1.upto(N+1){|k|
	R<<k.times.map{|i|D[k-1]+R[i]-(k-i-1)*A+(k-i-1)*(k-i)/2*B}.min
}
p R[-1]