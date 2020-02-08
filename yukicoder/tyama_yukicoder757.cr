#!/usr/bin/env crystal
require "big/big_int"
starting=1
base=BigInt.new(gets.not_nil!)
while (s=gets)!=nil
	n=BigInt.new(s.not_nil!,base: base)+(starting-2)
	digits=1
	expbase=BigInt.new("1")
	if false
		while (x=expbase*(digits*(base-1)))<=n
			digits+=1
			expbase*=base
			n-=x
		end
	else
		if false
			while digits*base**digits-(base**digits-1)//(base-1)<=n
				digits+=1
			end
		elsif false
			digits=1+(s.not_nil!.size.downto(0).find{|digits|
				z=base**digits;z*digits-(z-1)//(base-1)<=n
			}||0)
		else
			digits=(1..s.not_nil!.size).bsearch{|digits|
				z=base**digits;z*digits-(z-1)//(base-1)>n
			}||s.not_nil!.size
		end
		expbase=base**(digits-1)
		n-=(digits-1)*expbase-(expbase-1)//(base-1)
	end
	num=expbase+n//digits
	d=digits-1-n%digits
	if false
		d.times{num//=base}
		puts num%base
	else
		puts num.to_s(base)[-d-1]
	end
end
