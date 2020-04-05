#!/usr/bin/ruby
t=gets.to_i
t.times{|i|
	print 'Case #%d: '%(i+1)
	s=gets.chomp.chars.map &:ord
	print '('*(s[0]-'0'.ord)
	print s[0].chr
	s.each_cons(2){|x,y|
		x>y and print ')'*(x-y)
		x<y and print '('*(y-x)
		print y.chr
	}
	print ')'*(s[-1]-'0'.ord)
	puts
}
