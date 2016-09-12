#!/usr/bin/ruby
a,b=gets.split.map(&:to_f).sort
p Math.sqrt (b*b).send(a==b ? :+ : :-,a*a)