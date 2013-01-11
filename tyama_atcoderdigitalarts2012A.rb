#!/usr/bin/ruby
A,N,*F=STDIN.read.split("\n")
puts A.split.map{|a|F.any?{|f|a=~/^#{f.gsub('*','.')}$/}?'*'*a.length: a}*' '