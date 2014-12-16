#!/usr/bin/env ruby
T=[
0b1111110,
0b0110000,
0b1101101,
0b1111001,
0b0110011,
0b1011011,
0b1011111,
0b1110000,
0b1111111,
0b1111011,
]
p gets.chomp.chars.map{|c|n=c.to_i;T.count{|e|e&T[n]==T[n]}}.reduce(:*)