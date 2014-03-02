#!/usr/bin/ruby
h=Hash.new(0)
h['A']=h['D']=h['O']=h['P']=h['Q']=h['R']=1
h['B']=2
n='UTPC'.chars.map{|c|h[c]}
m=gets.chomp.chars.map{|c|h[c]}
puts ==m ? :yes : :no