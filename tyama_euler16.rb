#!/usr/bin/ruby
p((2**1000).to_s.split('').map(&:to_i).reduce(&:+))