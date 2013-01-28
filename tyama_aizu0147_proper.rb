#!/usr/bin/ruby
W=17
Z=100
q=[]
r=[]
sheet=Array.new(W)
t=0
loop{
	if t%5==0
		q << t/5
	end
	W.times{|i|
		if sheet[i]
			sheet[i]-=1
			sheet[i]=nil if sheet[i]==0
		end
	}
	while q.size>0
		l=(q[0]%5==1 ? 5 : 2)
		_p=(0..W-l).find{|i|sheet[i,l]==[nil]*l}
		break if !_p
		_p.step(_p+l-1){|i|
			sheet[i]=17*(q[0]%2)+3*(q[0]%3)+19
		}
		r<<t-q[0]*5
		q.shift
	end
	break if r.length>=Z
	t+=1
}
while gets
p r[$_.to_i]end