#!/usr/bin/ruby
#pipe to little R
puts "library(ape)"
f=nil
while gets
if f then puts "cat(' ')" end
f=1
tree=$_.chomp
a,b=gets.chomp.split
gets
puts <<EOM
t=read.tree(text='#{tree}')
cat(cophenetic(t)['#{a}','#{b}'])
EOM
end