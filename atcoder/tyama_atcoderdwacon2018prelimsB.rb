#!/usr/bin/ruby
s=gets.chomp;i=0;i+=1 while s.gsub!('25','');p s.empty? ? i : -1
