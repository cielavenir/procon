#!/usr/bin/env crystal
def calc(a)
	n=a.size
	w=[0]*(n*2+2)
	ret=0_i64
	a.reverse_each{|e|
		idx=e+n;while idx>0;ret+=w[idx];idx&=idx-1;end
		idx=e+n+1;while idx<w.size;w[idx]+=1;idx+=-idx&idx;end
	}
	ret
end
a=ARGF.gets_to_end.split.map &.to_i
n=a.shift
p a.uniq.sort.bsearch{|x|
	b=[0]
	a.each{|e|b<<b[-1]+(e>x ? 1 : -1)}
	calc(b)>=n.to_i64*(n+1)/4+1
}
