#!/usr/bin/ruby
while(n=gets.chomp)!='0'
	s=n.split('').map(&:to_i)
	a='%02d'%[s[0]*s[1]]
	b='%02d'%[s[1]*s[2]]
	n=a.reverse.to_i+b.reverse.to_i
	n=n*10-99 if n%10!=0
	puts a+b+'%02d'%n
end