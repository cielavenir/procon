#!/usr/bin/ruby
t=['nil','un','bi','tri','quad','pent','hex','sept','oct','enn']
puts (gets.chomp.split('').map{|e|t[e.to_i]}*''+'ium').gsub('ii','i').gsub('ennn','enn').capitalize