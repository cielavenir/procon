#!/usr/bin/ruby
A=%w(D C H S)
B=%w(A 2 3 4 5 6 7 8 9 T J Q K)
gets
puts gets.split.sort_by{|e|[A.index(e[0]),B.index(e[1])]}*' '