#!/usr/bin/ruby
x,y=gets.split.map &:to_i
puts (x==0&&y==1)||(x+2>y&&y>1&&(x-y)%2>0)?:Yes: :No
