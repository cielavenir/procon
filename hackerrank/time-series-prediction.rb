#!/usr/bin/ruby
a=$<.map(&:to_i)[-30,30]
p *[a.reduce(:+)/a.size.to_f]*30
