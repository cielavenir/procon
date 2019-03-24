#!/usr/bin/ruby
r=0
n=gets.to_i
s=gets.chomp
n.times{|i|(i+2).step(n-1,2){|j|k=i+(j-i)/2;s[i]==?U&&s[k]==?M&&s[j]==?G&&r+=1}}
p r
