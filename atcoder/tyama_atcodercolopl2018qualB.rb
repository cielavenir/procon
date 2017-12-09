#!/usr/bin/ruby
n,x=gets.split.map &:to_i
r=0
gets.chomp.chars{|c|
n=gets.to_i
r+=c=='0'?n:[n,x].min
}
p r
