#!/usr/bin/ruby
s=gets.chomp
c=s.count(?o)
puts c>0&&s.size%c>0?:No: :Yes
