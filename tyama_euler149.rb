#!/usr/bin/ruby
class NilClass
	def coerce(o) return [o,0] end
end

M=2000
a=[]
(1..55).each{|k|a<<(100003-200003*k+300007*k**3)%10**6-500000}
(56..M*M).each{|k|a<<(a[k-1-24]+a[k-1-55]+10**6)%10**6-500000}
b=a.each_slice(M).to_a
r=0
b.size.times{|i|
	d=[]
	b[i].size.times{|j|
		d<<[b[i][j],b[i][j]+d[j-1]].max
	}
	r=[r,d.last].max
}
b[0].size.times{|i|
	d=[]
	b.size.times{|j|
		d<<[b[j][i],b[j][i]+d[j-1]].max
	}
	r=[r,d.last].max
}
b2=b.transpose
1.step(M){|i|
	d=[]
	i.times{|j|
		d<<[b[2000-i+j][2000-i+j],b[2000-i+j][2000-i+j]+d[j-1]].max
	}
	r=[r,d.last].max
}
1.step(M){|i|
	d=[]
	i.times{|j|
		d<<[b2[2000-i+j][2000-i+j],b2[2000-i+j][2000-i+j]+d[j-1]].max
	}
	r=[r,d.last].max
}
c=b.map{|e|e.reverse}
c2=c.transpose
#similar code... but not required...
p r