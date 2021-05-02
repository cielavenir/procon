#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
head=tail=q=r=0
while tail<n
	while tail<n&&q&a[tail]==0
		q|=a[tail]
		tail+=1
		r+=tail-head
	end
	q^=a[head]
	head+=1
end
p r
