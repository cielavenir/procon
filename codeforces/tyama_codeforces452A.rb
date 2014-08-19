#!/usr/bin/ruby
t=["vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]
n=gets.to_i
s=gets.chomp
puts t.find{|e|e.size==n && n.times.all?{|i|s[i]==e[i]||s[i,1]=='.'}}