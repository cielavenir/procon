#!/usr/bin/ruby
s=gets.chomp
p [0,1].map{|i|t='';s.size.times{t<<i.to_s;i^=1};s.size.times.count{|j|t[j]!=s[j]}}.min
