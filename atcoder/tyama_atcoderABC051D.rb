#!/usr/bin/ruby
n,m=gets.split.map &:to_i
a,b,c=$<.map{|e|e.split.map &:to_i}.transpose
d=n.times.map{|i|[1<<30]*i+[0]+[1<<30]*(n-i-1)}
m.times{|i|
	d[a[i]-1][b[i]-1]=d[b[i]-1][a[i]-1]=c[i]
}
n.times{|k|n.times{|i|n.times{|j|
	d[i][j]=[d[i][j],d[i][k]+d[k][j]].min
}}}
p m.times.count{|i|
	n.times.all?{|s|
		d[s][a[i]-1]+c[i]!=d[s][b[i]-1]
	}
}
