#!/usr/bin/ruby
$t={}
def collatz(n)
	return 0 if n==1
	n=n%2==0 ? n/2 : 3*n+1
	$t[n]||=collatz(n)+1
end
p 2.step(999999).map{|i|[collatz(i),i]}.max[1]