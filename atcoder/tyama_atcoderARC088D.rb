#!/usr/bin/ruby
s=gets.chomp;n=s.size;p (1..n).select{|i|s[i-1]!=s[i]}.map{|i|[i,n-i].max}.min||n
