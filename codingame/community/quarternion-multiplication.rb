#!/usr/bin/ruby
T=[
	[0,0,0,0,0],
	[0,1,2,3,4],
	[0,2,-1,4,-3],
	[0,3,-4,-1,2],
	[0,4,3,-2,-1],
]
mul=lambda{|a,b|
	r=[0]*5
	1.upto(4){|i|1.upto(4){|j|
		t=T[i][j].abs
		r[t]+=T[i][j]/t*a[i]*b[j]
	}}
	r
}

a=gets.chomp[1..-2].split(')(').map{|e|
	r=[0]*5
	a=e.scan(/([+-]?\d*)([ijk]?)/)
	a.each{|f|
		y={''=>1,'i'=>2,'j'=>3,'k'=>4}[f[1]]
		z=f[0].scan(/\d+/).empty?
		if !z||y!=1
			x=(z ? f[0]+'1' : f[0]).to_i
			r[y]=x
		end
	}
	r
}
s=''
a=a.reduce(&mul)
[2,3,4,1].each{|i|
	if a[i]!=0
		s<<'+' if !s.empty?
		if a[i]<0
			s<<'-'
			a[i]=-a[i]
		end
		x=['','','i','j','k'][i]
		s<<a[i].to_s if x.empty?||a[i]!=1
		s<<x
	end
}
puts s.gsub('+-','-')