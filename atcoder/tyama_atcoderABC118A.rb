#!/usr/bin/ruby
a,b=gets.split.map &:to_i;p b.send(b%a>0?:-: :+,a)
