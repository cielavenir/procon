#!/usr/bin/ruby
def rec2c(a,n)
	if n==0 then []
	else
		a.length.times{|i|
			if n>=a[i] && a.find{|e|(n-a[i])%e==0}
				r=rec2c(a,n-a[i])
				if r then return [a[i]]+r end
			end
		}
	end
end
m={10000=>'ONE HUNDRED',5000=>'FIFTY',2000=>'TWENTY',1000=>'TEN',500=>'FIVE',200=>'TWO',100=>'ONE',50=>'HALF DOLLAR',25=>'QUARTER',10=>'DIME',5=>'NICKEL',1=>'PENNY'}
while gets
n=-$_.split(';').map{|e|(e.to_f*100).to_i}.reduce(:-)
puts n<0 ? 'ERROR' : n==0 ? 'ZERO' : rec2c(m.keys.sort.reverse,n).map{|e|m[e]}.sort*','
end