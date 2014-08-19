#!/usr/bin/ruby
a=[]
(2..1/0.0).each{|i|
	v=i
	99.times{|j|
		v*=i
		a<<v if v.to_s.chars.map(&:to_i).reduce(:+)==i
	}
	break if a.size>99
}
p a.sort[29] # 248155780267521