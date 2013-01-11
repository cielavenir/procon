#!/usr/bin/ruby
p 101.times.reduce(&:+)**2-101.times.reduce(0){|s,i|s+=i**2}