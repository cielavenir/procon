#!/usr/bin/ruby
S,t=$<.map &:chomp
r=nil
(0..S.size-t.size).each{|i|
	s=S.dup
	if t.size.times.all?{|j|
		if s[i+j]=='?' || s[i+j]==t[j]
			s[i+j]=t[j]
		end
	}
		s.tr!('?','a')
		r=s if !r||r>s
	end
}
puts r||:UNRESTORABLE
