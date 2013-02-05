#!/usr/bin/ruby
m,M=ARGV.map(&:to_i);m.step(M){|n|n%3<1&&x=:Fizz;puts n%5<1?"#{x}Buzz":x||n}