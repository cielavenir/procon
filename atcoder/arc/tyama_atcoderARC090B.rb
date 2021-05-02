#!/usr/bin/ruby
r=0
a,b,c,x=$<.map &:to_i
(0..x/500).each{|i|(0..(x-500*i)/100).each{|j|
	k0=x-500*i-100*j
	r+=1 if k0%50==0&&c>=k0/50&&a>=i&&b>=j
}}
p r
