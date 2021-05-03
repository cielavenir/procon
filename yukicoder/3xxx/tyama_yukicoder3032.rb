#!/usr/bin/ruby
T=[60,61,62].map(&:chr)*''
gets.to_i.times{
a,b=gets.split.map &:to_i
puts T[-~a.send(T,b)%3]
}
