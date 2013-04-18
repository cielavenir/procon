#!/usr/bin/ruby

def solve1(n,k)
	a=n.times.map{|i|i}
	b=a;c=[];r=0
	loop{
		r+=1
		(n/k).times{|j|
			(k-1).downto(0){|i|
				c.push(b[i*(n/k)+j])
			}
		}
		#p c
		break if c==a
		b=c;c=[]
	}
	r
end

def solve2(n,k)
	#limit=50000
	i=0
	r=0
	_k=k-1
	_n=n/k
	_k_n=_k*_n
	begin
		#j=i/k
		#i=(_k-i+j*k)*_n+j
		#i=(_k-i%k)*_n+i/k
		i=i/k-i%k*_n+_k_n
		r+=1
	end while i!=0&&i!=n-1 #&&r<limit
	#if r==limit then r=-1 end
	r*=2 if i==n-1
	r
end

if false
Z=10**8
Z.step(Z){|i|
	1.step(i){|j|
		next if i%j>0
		puts "#{i} #{j} #{solve2(i,j)}"
	}
}
else
gets.to_i.times{
	n,k=gets.split.map(&:to_i)
	p solve2(n,k)
}
end