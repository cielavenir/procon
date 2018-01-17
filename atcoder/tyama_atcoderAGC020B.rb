#!/usr/bin/ruby
l=r=2;gets;puts gets.split.reverse.any?{|e|e=e.to_i;(l=e+~-l/e*e)>r=r/e*e+~-e}?-1:[l,r]*' '
