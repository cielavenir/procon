#!/usr/bin/ruby
n=gets.chomp.split(" ").map!{|i|i=i.to_i}
a=gets.chomp.split(" ").map!{|i|i=i.to_i}.sort
b=a.reverse
h=Hash.new
h.default=0
n[1].times{|i|
  h[gets.chomp]+=1;
}
g=h.values.sort.reverse
m=M=0
g.length.times{|i|
  m+=g[i]*a[i]
  M+=g[i]*b[i]
}
puts "#{m} #{M}"