#!/usr/bin/ruby
n,k=gets.split.map &:to_i
a=$<.map{|e|e.split.map &:to_i}
p ma=(0..10**9).bsearch{|e|
	tail=-k
	!!a.each{|t,d|
		if d>e
			if t-tail<k
				break
			else
				tail=t
			end
		end
	}
}
t,d=a.transpose
ng=[false]*n
tail=t[-1]+k
(n-1).downto(s=0){|i|
	if d[i]>ma
		tail=t[i]
	elsif tail-t[i]<k
		ng[i]=true
	end
}
m=[j=0]
tail=-k
n.times{|i|
	if d[i]>ma
		d[i]=0
		tail=t[i]
	else
		s+=d[i]
		d[i]=0 if ng[i]||t[i]-tail<k
	end
	j+=1 while t[i]-t[j]>=k
	m[i+1]=[m[i],m[j]+d[i]].max
}
p s-m[n]
