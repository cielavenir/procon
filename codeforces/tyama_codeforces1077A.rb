#!/usr/bin/ruby
gets;p *$<.map{|e|a,b,k=e.split.map &:to_i;k/2*(a-b)+k%2*a}
