#!/usr/bin/ruby
s=gets.chomp
p s.size%2==1 ? -1 : (s.count(?L)-s.count(?R)).abs+(s.count(?U)-s.count(?D)).abs>>1