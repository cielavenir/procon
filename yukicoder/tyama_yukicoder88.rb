#!/usr/bin/ruby
A=['oda','yukiko'];x=A.index(gets.chomp);n=$<.map{|e|e.count('w')+e.count('b')}.reduce(:+);puts A[(x+n)%2]