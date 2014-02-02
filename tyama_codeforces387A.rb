#!/usr/bin/ruby
t=2.times.map{a,b=gets.split(':').map(&:to_i);a*60+b}.reduce(:-)
t+=1440 if t<0
puts '%02d:%02d'%[t/60,t%60]