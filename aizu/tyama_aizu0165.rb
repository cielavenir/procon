#!/usr/bin/ruby
require 'prime'
n=[0];cnt=1
Prime.each{|e|
	while cnt<e do n<<n.last;cnt+=1 end
	n<<n.last+1;cnt+=1
	break if e>10**6
}
while(m=gets.to_i)>0
	r=-m
	m.times{
		p,m=gets.split.map(&:to_i)
		j=p-m-1
		j=0 if j<0
		k=p+m
		k=10**6-1 if k>=10**6
		r+=n[k]-n[j]
	}
	p r
end