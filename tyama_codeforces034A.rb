#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i)
r=a.size.times.map{|i|[(a[i]-a[(i+1)%a.size]).abs,i]}.min.pop
puts "#{r+1} #{(r+1)%a.size+1}"