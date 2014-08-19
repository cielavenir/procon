#!/usr/bin/ruby
sum=0
[*0..9].permutation{|a|
	if a[0]==0 then next end
	s=a*''
	if s[1,3].to_i%2==0 && s[2,3].to_i%3==0 && s[3,3].to_i%5==0 && s[4,3].to_i%7==0 && s[5,3].to_i%11==0 && s[6,3].to_i%13==0 && s[7,3].to_i%17==0 then sum+=s.to_i end
}
p sum