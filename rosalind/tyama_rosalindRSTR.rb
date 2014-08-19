#!/usr/bin/ruby
n,r=gets.split.map(&:to_f)
s=gets
puts 1-(1-10**(Math.log10(r/2)*s.scan(/[CG]/).count+Math.log10(0.5-r/2)*s.scan(/[AT]/).count))**n