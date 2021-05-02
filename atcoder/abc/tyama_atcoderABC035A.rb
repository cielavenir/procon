#!/usr/bin/ruby
puts Rational(*gets.split.map(&:to_i)).to_s.sub('/',':')