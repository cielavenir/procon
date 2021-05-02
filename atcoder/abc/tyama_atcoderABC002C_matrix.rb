#!/usr/bin/ruby
#a=gets.split.map(&:to_f).each_slice(2).to_a
#p 3.times.map{|i|a[i][0]*(a[(i+1)%3][1]-a[(i+2)%3][1])}.reduce(:+).abs/2.0
a=gets.split.map(&:to_f)
n=0
3.times{|i|n+=a[i*2]*(a[(i+1)%3*2+1]-a[(i+2)%3*2+1])}
p n.abs/2.0