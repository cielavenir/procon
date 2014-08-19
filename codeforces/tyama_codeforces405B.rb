#!/usr/bin/ruby
gets
s=gets.chomp
loop{
	t=s.dup
	t.size.times{|i|
		next if t[i,1]!='.'
		r=0<i&&s[i-1,1]=='R'
		l=i<t.size-1&&s[i+1,1]=='L'
		if r^l
			t[i,1] = r ? 'R' : 'L'
		end
	}
	break if s==t
	s=t
}
p s.scan('.').count