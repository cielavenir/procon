#!/usr/bin/ruby
300.times{|a|a.step(400){|b|x=a*a+b*b;if (c=(x**0.5).to_i)**2==x&&a+b+c==1000 then p a*b*c;exit end}}