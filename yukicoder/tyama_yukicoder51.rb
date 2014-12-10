#!/usr/bin/ruby
w,d=$<.map(&:to_i);d.downto(2){|i|w-=w/(i*i)};p w