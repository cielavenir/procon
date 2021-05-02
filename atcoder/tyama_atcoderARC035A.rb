#!/usr/bin/ruby
s=gets.chomp.bytes.to_a
puts s.zip(s.reverse).all?{|x,y|x==42||y==42||x==y} ? :YES : :NO