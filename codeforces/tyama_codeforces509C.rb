#!/usr/bin/env ruby
cur=[0]
gets.to_i.times{
	n=gets.to_i
	s=0
	idx=(cur.size.times.find{|i|s+=cur[i];s>=n}||cur.size)-1
	if idx==-1
		a=[1]+cur.map{|e|0}
	else
		a=cur.dup
		while a[idx]==9
			idx-=1
		end
		if idx>=0
			a[idx]+=1
		else
			a=[1]+a
			idx=0
		end
		(idx+1).upto(a.size-1){|i|a[i]=0}
	end
	fill=n-a.reduce(:+)
	idx=a.size-1
	while idx>=0
		a[idx]+=fill
		fill=0
		if a[idx]>9
			fill=a[idx]-9
			a[idx]=9
		end
		idx-=1
	end
	d,r=fill.divmod(9)
	a=(r==0?[]:[r])+[9]*d+a
	cur=a
	puts cur*''
}