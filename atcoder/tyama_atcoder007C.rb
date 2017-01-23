#!/usr/bin/ruby
h={}
(l=(s=gets.chomp).size).times{|i|t=s[i..-1]+s[0,i];h[i]=(0...l).select{|j|t[j]==?o}}
p (0...1<<l).map{|i|a=[nil]*l;c=(0...l).count{|j|i[j]>0&&h[j].map{|k|a[k]=1}};a.all?? c:l}.min
