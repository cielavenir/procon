#!/usr/bin/ruby
a=gets.chomp.split('!',2)
x=a[1] ? a[1].gsub('-','').size+1 : 0
puts '-'*(a[0].size%2)+'!'*(x==0 ? 0 : (x-1)%2+1)