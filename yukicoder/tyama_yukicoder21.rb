#!/usr/bin/ruby
x,y=$<.drop(2).map(&:to_i).minmax;p y-x