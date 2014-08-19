#!/usr/bin/ruby
#wget -O - http://projecteuler.net/project/cipher1.txt
#key is "god" :p
s=gets.split(',').map(&:to_i)
97.step(122){|a|
	97.step(122){|b|
		97.step(122){|c|
			t=s.dup
			m=[a,b,c]
			t.size.times{|i|
				t[i]^=m[i%3]
			}
			if t.map(&:chr).join.index(' the ') then p t.reduce(:+);exit end
		}
	}
}