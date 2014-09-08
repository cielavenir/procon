#!/usr/bin/ruby
A=[2,3,5,7,11,13,17]
sum=0
[*0..gets.to_i].permutation{|a|
	#if a[0]==0 then next end
	s=a*''
	if (1..a.size-3).all?{|i|s[i,3].to_i%A[i-1]==0}
		sum+=s.to_i
	end
}
p sum
__END__
9