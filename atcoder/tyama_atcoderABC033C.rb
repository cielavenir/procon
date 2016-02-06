#!/usr/bin/ruby
#puts gets.chomp.split(?+).count{|e|e.split(?*).all?{|f|f!=?0}}
puts gets.split(?+).count{|e|eval(e)>0}