#!/usr/bin/ruby
a,b,c,d=gets.split.map(&:to_f)
puts [:DRAW,:TAKAHASHI,:AOKI][b/a<=>d/c]