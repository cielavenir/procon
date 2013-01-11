#!/usr/bin/ruby
gets.to_i.times{y,m,d=gets.split.map &:to_i;y-=1;m-=1;p 196471-y*195-y/3*5-m*20+(y%3!=2?m/2:0)-d}