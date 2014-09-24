#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
n.times{p k.times.count{eval gets.sub('=','==')}}