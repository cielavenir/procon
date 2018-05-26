#!/usr/bin/env crystal
#http://nabetani.sakura.ne.jp/hena/orde24tancho/
#https://qiita.com/Nabetani/items/928d6a94d83c21ef64d7

def comb(n,k)
	r=1_i64
	k.times{|i|
		r=r*(n-i)/(i+1)
	}
	r
end

STDOUT.sync=true
while l_=gets
	line=l_.chomp.split(',')
	b=line[0].to_i-1
	n=line[1].to_i64-1
	topdigit=1
	loop{
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
			x=comb(b-curnumber,d)
			break if x>n
			n-=x
			curnumber+=1
		}
		print curnumber.to_s(b+1)
	}
	puts
end
