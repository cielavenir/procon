#!/usr/bin/env ruby
def gen(n,prevn,_digits)
	return to_enum(:gen,n,prevn,_digits) if !block_given?
	d,r=n.divmod(9)
	digits=[_digits,(r==0?0:1)+d].max
	#digits+=1 if n<prevn
	z=digits-((r==0?0:1)+d)
	a=[0]*z+(r==0?[]:[r])+[9]*d
	idx=0.upto(digits-1).find{|i|a[i]!=0}
	a[0]+=1
	a[idx]-=1
	loop{
		yield a.join.to_i
		idx_down=(a.size-1).downto(0).find{|i|a[i]!=0}
		if idx_down!=0 && idx_up=(idx_down-1).downto(0).find{|i|a[i]<9}
			a[idx_down]-=1
			a[idx_up]+=1
			a=a[0,idx_up+1]+a[idx_up+1..-1].reverse
		else
			digits+=1
			d,r=(n-1).divmod(9)
			z=digits-(1+(r==0?0:1)+d)
			a=[1]+[0]*z+(r==0?[]:[r])+[9]*d
		end
	}
end
#p gen(4,0).take(30)
cur=0
prevn=0
gets.to_i.times{
	n=gets.to_i
	nxt=gen(n,prevn,cur.to_s.size).find{|e|e>cur}
	sum=nxt.to_s.chars.map(&:to_i).reduce(:+)
	p nxt
	cur=nxt
	prevn=n
}