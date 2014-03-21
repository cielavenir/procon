#!/usr/bin/ruby
while(n,k=gets.split.map(&:to_i))!=[0,0]
n.times{p k.times.count{eval gets.sub('=','==')}}end