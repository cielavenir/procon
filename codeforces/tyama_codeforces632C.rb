#!/usr/bin/ruby
gets;puts$<.map(&:chomp).sort{|a,b|a+b<=>b+a}*''