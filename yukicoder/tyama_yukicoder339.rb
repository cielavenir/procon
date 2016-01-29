#!/usr/bin/ruby
gets;p 100/$<.map(&:to_i).reduce(&:gcd)