#!/usr/bin/ruby
def perform(n,f)
	d=1
	d+=1 while 10**d<=n
	r=f&&(n+1)/10**(d-1)==2&&n%10==1 ? 1 : 0
	return r if n<2
	return r+1 if n<12

	(d-2).downto(0){|i|
		a,x=n.divmod(10**(i+2))
		b,c=x.divmod(10**(i+0))
		if b>12
			a+=1
			c=0
		elsif b<12
			c=0
		else
			c+=1
		end
		r+=a*10**i+c
	}
	1.upto(d-1){|i|
		r+=i<3 ? 1 : 10**(i-2)
	}
	if n/10**(d-1)>2
		r+=10**(d-2)
	elsif n/10**(d-1)==2
		r+=(n-2*10**(d-1))/10+(n%10>=2 ? 1 : 0)
	end
	r
end
a,b=gets.split.map(&:to_i)
p perform(b,false)-perform(a-1,true)