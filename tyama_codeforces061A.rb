#!/usr/bin/ruby
s=gets.chomp
printf("%0#{s.size}b",s.to_i(2)^gets.to_i(2))