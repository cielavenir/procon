#!/usr/bin/ruby
q=[1,2];r=[0,1]
a=2.step(100).map{|i|
	q.push((i%3==0?(i)/3*2:1)*q[i-1]+q[i-2])
	r.push((i%3==0?(i)/3*2:1)*r[i-1]+r[i-2])
}
p q[100].to_s.split('').map(&:to_i).reduce(&:+)