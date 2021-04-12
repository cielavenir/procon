#!/usr/bin/ruby
def perm2idx(a)
	lst=[*1..a.size]
	raise if lst!=a.sort
	fact=[1]
	(1...a.size).each{|i|fact<<fact[-1]*i}
	fact.reverse!
	r=0
	a.each_with_index{|e,i|
		idx=lst.index(e)
		r+=fact[i]*idx
		lst.delete_at(idx)
	}
	r
end
def idx2perm(n,siz)
	lst=[*1..siz]
	fact=[1]
	(1...siz).each{|i|fact<<fact[-1]*i}
	fact.reverse!
	raise if fact[0]*siz<=n
	a=[]
	fact.each{|e|
		z=n/e
		n%=e
		a<<lst[z]
		lst.delete_at(z)
	}
	a
end
def reverseperm(a)
	r=[nil]*a.size
	a.size.times{|i|
		r[a[i]-1]=i+1
	}
	r
end
p perm2idx reverseperm idx2perm *gets.split.map(&:to_i)
