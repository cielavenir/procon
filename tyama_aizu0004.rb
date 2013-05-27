#!/usr/bin/ruby
puts$<.map{|z|a,b,c,d,e,f=z.split.map(&:to_f);x=a*e-b*d;"%.3f %.3f"%[(e*c-b*f)/x+0,(a*f-d*c)/x+0]}