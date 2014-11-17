#!/usr/bin/ruby
N=gets.to_i
a=[nil]*(N+1)
a[1]=1
q=[1]
while !q.empty?
	cur=q.shift
	d=cur.to_s(2).count('1')
	[-d,d].each{|e|
		if 1<=cur+e&&cur+e<=N && !a[cur+e]
			a[cur+e]=a[cur]+1
			q.push(cur+e)
		end
	}
end
p a[N]||-1