#!/usr/bin/ruby
u,b,h=gets.split(',').map(&:to_f)
puts '%.2f'%[(u+b)*h/2]
