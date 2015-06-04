#!/usr/bin/ruby
puts gets.chomp.bytes.map{|e|((e-48+1)%10+48).chr}*''