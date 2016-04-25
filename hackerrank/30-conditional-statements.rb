#!/usr/bin/ruby
n=gets.to_i
puts n%2==1||(6..20).include?(n) ? 'Weird' : 'Not Weird'