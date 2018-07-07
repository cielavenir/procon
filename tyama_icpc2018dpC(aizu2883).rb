#!/usr/bin/ruby
O=->a,b{a|b}.curry
A=->a,b{a&b}.curry
X=->a,b{a^b}.curry
loop{
	s=gets.chomp.tr('+*^','OAX')
	break if s=='.'
	'abcd'.chars{|c|s.gsub!(c,'[%s]'%c)}
	s=s[1...-1]
	n=gets.to_i
	r=eval(s.tr('abcd','%04d'%n))
	puts '%d %d'%[r,10000.times.count{|i|r==eval(s.tr('abcd','%04d'%i))}]
}
