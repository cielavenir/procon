#!/usr/bin/ruby
n,t=gets.split.map(&:to_i)
gets
a=n.times.map{gets.split.map{|e|{:subscore=>e.to_i}}}
n.times{|i|
	x=gets.split.map(&:to_i)
	x.length.times{|j|
		score=a[i][j][:subscore]-(j>0?a[i][j-1][:subscore]:0)
		a[i][j][:problem]=i
		a[i][j][:parttime]=x[j]
		a[i][j][:partscore]=score
	}
}
r=0
z=0
while a.length>0
	a.sort_by!{|e|[e[0][:subscore],e[0][:problem]]}
	#a[0][0] (the problem whose current sub-problem has lowest subscore)'s current sub-problem
	break if z+a[0][0][:parttime]>t
	r+=a[0][0][:partscore]
	z+=a[0][0][:parttime]
	a[0].shift
	a.shift if a[0].length==0
end
p r