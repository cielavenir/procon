#!/usr/bin/ruby
n=gets.to_i;a=gets.split.map(&:to_i)
s=0;r=nil
n.times{|i|
	s+=a[i]
	r=i if s!=0
}
if !r
	puts :NO
elsif s!=0
	puts "YES\n1\n1 %d"%n
else
	puts "YES\n2\n1 %d\n%d %d"%[r+1,r+2,n]
end
