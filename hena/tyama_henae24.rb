#!/usr/bin/env ruby
#http://nabetani.sakura.ne.jp/hena/orde24tancho/
#https://qiita.com/Nabetani/items/928d6a94d83c21ef64d7

def comb(n,k)
	r=1
	k.times{|i|
		r=r*(n-i)/(i+1)
	}
	r
end

STDOUT.sync=true
while gets
	b,n=$_.chomp.split(',').map{|e|e.to_i-1}
	topdigit=1
	loop{
		#b種類で作れるitopdigit桁の数
		x=comb(b,topdigit)
		break if b<topdigit || x>n
		n-=x
		topdigit+=1
	}
	if b<topdigit
		puts :-
		next
	end
	topdigit-=1
	curnumber=0
	topdigit.downto(0){|d|
		curnumber+=1
		loop{
			#b-curnumber種類の数で作れるd桁の数
			x=comb(b-curnumber,d)
			break if x>n
			n-=x
			curnumber+=1
		}
		print curnumber.to_s(b+1)
	}
	puts
end
