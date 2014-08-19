#!/usr/bin/ruby
r=0
3.step(1000){|i|
	r+= i%2==0 ? i*(i-1) : i*(i-2)
}
p r