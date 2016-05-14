#!/usr/bin/ruby
starting=1
bse=10
while gets
	n=$_.to_i
	n+=starting-2
	digits=1
	expbase=1
	while (x=digits*expbase*(bse-1))<=n
		n-=x
		digits+=1
		expbase*=bse
	end
	num=expbase+n/digits
	d=digits-1-n%digits
	d.times{
		num/=bse
	}
	puts num%bse
end