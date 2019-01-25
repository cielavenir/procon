#!/usr/bin/ruby
s=gets.chomp
t=[]
s.bytes{|c|
t<<c
t.pop(2) if c==t[-2]
}
puts (s.size-t.size)/2%2>0 ? :Yes : :No
