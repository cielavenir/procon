#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
s,idx=[0,1].map{|x|
	idx=[]
	s=0
	x.step(n-1,2){|i|
		if a[i]>0
			idx<<i
			s+=a[i]
		end
	}
	[s,idx]
}.max

if s<1
	i=(0...n).max_by{|i|a[i]}
	p a[i]
	r=n.downto(i+2).to_a+[1]*i
else
	p s
	r=n.downto(idx[-1]+2).to_a
	idx.reverse.each_cons(2){|j,i|
		r+=((i+j)/2+1).downto(i+2).to_a
	}
	r+=[1]*idx[0]
end
p r.size,*r
