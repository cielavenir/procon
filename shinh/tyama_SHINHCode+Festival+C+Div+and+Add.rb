#!/usr/bin/ruby
#問題が小さいのでメモ化は必要ない

def d(n)
	r=0
	(1...n).map{|i|n%i==0&&r=[r,d(i)].max}
	(r+=n%10;n/=10)while n>0
	r
end
puts $<.map{|e|d e.to_i}