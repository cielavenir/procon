#!/usr/bin/ruby
n=gets.to_i
r=0
(3..9).each{|i|[3,5,7].repeated_permutation(i){|a|r+=1 if a.uniq.size==3&&a.join.to_i<=n}}
p r
