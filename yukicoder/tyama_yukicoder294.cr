#!/usr/bin/env crystal
def comb(n,r)
	if r==0
		return 1_i64
	end
	ret=1_i64
	if r>n//2
		r=n-r
	end
	r.times{|i|
		ret=ret*(n-i)//(i+1)
	}
	return ret
end
def popcnt32(n)
	m1=0x55555555
	m2=0x33333333
	m4=0x0f0f0f0f
	m8=0x00ff00ff
	m16=0x0000ffff
	n=((n>>1)&m1)+(n&m1)
	n=((n>>2)&m2)+(n&m2)
	n=((n>>4)&m4)+(n&m4)
	n=((n>>8)&m8)+(n&m8)
	n=((n>>16)&m16)+(n&m16)
	return n
end

n=gets.not_nil!.to_i
digits=2
loop{
	s=0
	five=2
	while five<=digits
		s+=comb(digits,five)
		five+=3
	end
	break if n<=s
	n-=s
	digits+=1
}
(1..1/0.0).each{|i|
	if popcnt32(i)%3==2
		n-=1
		if n==0
			puts sprintf("%0"+digits.to_s+"b",i).tr("01","35")+"5"
			exit
		end
	end
}
