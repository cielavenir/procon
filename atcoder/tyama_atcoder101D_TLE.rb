#!/usr/bin/ruby
def calc(a)
	n=a.size
	w=[0]*(n*2+2)
	ret=0
	a.reverse_each{|e|
		idx=e+n;(ret+=w[idx];idx&=idx-1)while idx>0
		idx=e+n+1;(w[idx]+=1;idx+=idx&-idx) while idx<w.size
	}
	ret
end
n,*a=`dd`.split.map &:to_i
p a.uniq.sort.bsearch{|x|
	*b=0
	a.each{|e|b<<b[-1]+(e>x ? 1 : -1)}
	calc(b)>=n*(n+1)/4+1
}
