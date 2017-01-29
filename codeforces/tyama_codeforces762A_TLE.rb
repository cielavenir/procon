#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
r=[]
i=1
while i*i<=n
	r<<i if n%i==0
	i+=1
end
q=r.size*2
q-=1 if r[-1]**2==n
p k>q ? -1 : k<=r.size ? r[k-1] : n/r[q-k]
