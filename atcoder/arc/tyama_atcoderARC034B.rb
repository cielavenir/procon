#!/usr/bin/ruby
N=gets.to_i
a=([0,N-153].max..N).select{|i|i+i.to_s.chars.map(&:to_i).reduce(:+)==N}
p a.size
p *a