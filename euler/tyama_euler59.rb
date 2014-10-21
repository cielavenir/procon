#!/usr/bin/ruby
#curl http://projecteuler.net/project/cipher1.txt
#key is "god" :p
LETTERS=[*'a'..'z',*'A'..'Z',*'0'..'9','(',')',';',':',',','.',"'",'?','!','-',' ']
#s=gets.split(',').map(&:to_i)
gets;s=gets.split.map(&:to_i)
97.step(122){|a|
	97.step(122){|b|
		97.step(122){|c|
			t=s.dup
			m=[a,b,c]
			t.size.times{|i|
				t[i]^=m[i%3]
			}
			_a=t.map(&:chr)
			#if _a.join.index(' the ') then p t.reduce(:+);exit end
			if _a.all?{|c|LETTERS.include?(c)} then puts m.map(&:chr)*'';exit end
		}
	}
}