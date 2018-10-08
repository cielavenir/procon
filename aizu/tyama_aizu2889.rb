#!/usr/bin/ruby
s=gets.chomp.chars
p [*1...s.size].combination(3).count{|e|
	t=s.dup
	e.reverse_each{|i|t.insert(i,'.')}
	t.join.split('.').all?{|_|
		n=_.to_i
		n<256 && n.to_s==_
	}
}
