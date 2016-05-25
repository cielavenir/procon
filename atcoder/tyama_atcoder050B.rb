#!/usr/bin/ruby
r,b,x,y=`dd`.split.map &:to_i;p (0..1<<60).bsearch{|k|r<k||b<k||(r-k)/~-x+(b-k)/~-y<k}-1