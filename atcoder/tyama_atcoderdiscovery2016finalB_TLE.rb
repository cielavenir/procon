#!/usr/bin/ruby
N,X=gets.split.map(&:to_i)
A=2.times.map{gets.split.map(&:to_i)}.transpose

if true
	a=A.sort_by{|t,v|[v,t]}
	ti=[*1..N]
	r=x=0
	p N.times{|i|
		t,v=a[N-i-1]
		idx=[*0...ti.size].bsearch{|i|ti[i]>t}||ti.size
		next if idx==0
		idx-=1
		ti.delete_at(idx)
		r+=1
		x+=v
		break if X<=x
	} ? -1 : r
else
	a=A.sort_by{|t,v|[t,-v]}
	s=0
	p (1..N).find{|i|
		a.shift while !a.empty?&&a[0][0]<i
		break if a.empty?
		s+=a[0][1]
		a.shift
		X<=s
	}||-1
end