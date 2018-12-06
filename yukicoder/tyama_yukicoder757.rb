#!/usr/bin/ruby
starting=1
bse=gets.to_i
while gets
	n=$_.to_i(bse)
	n+=starting-2
	digits=1
	expbase=1
	if false
		while (x=expbase*(digits*(bse-1)))<=n
			digits+=1
			expbase*=bse
			n-=x
		end
	else
		if false
			while (z=bse**digits;z*digits-(z-1)/(bse-1)<=n)
				digits+=1
			end
		elsif false
			digits=1+($_.size.downto(0).find{|digits|
				z=bse**digits;z*digits-(z-1)/(bse-1)<=n
			}||0)
		else
			digits=(1..$_.size).bsearch{|digits|
				z=bse**digits;z*digits-(z-1)/(bse-1)>n
			}||$_.size
		end
		expbase=bse**(digits-1)
		n-=(digits-1)*expbase-(expbase-1)/(bse-1)
	end
	num=expbase+n/digits
	d=digits-1-n%digits
	if false
		d.times{num/=bse}
		puts num%bse
	else
		puts num.to_s(bse)[-d-1]
	end
end

__END__
Sn   = 1*1*9 2*10*9 3*100*9 4*1000*9
10Sn =       1*10*9 2*100*9 3*1000*9  4*10000*9
-9Sn = 1*1*9 1*10*9 1*100*9 1*1000*9 -4*10000*9
-9Sn = (10**4-1)                     -4*10000*9

Si   = i*10**i - (10**i-1)/9
