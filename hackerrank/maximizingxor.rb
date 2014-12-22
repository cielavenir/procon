#!/usr/bin/ruby
l=gets.to_i
r=gets.to_i
ma=0
l.step(r){|i|
	i.step(r){|j|
		ma=[i^j,ma].max
	}
}
p ma