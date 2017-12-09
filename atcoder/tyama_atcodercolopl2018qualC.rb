#!/usr/bin/ruby
F=->a{a[0]?F[x=a[1..-1]]+F[x.select{|e|e.gcd(a[0])<2}]:1};A,B=gets.split.map &:to_i;p F[[*A..B]]
