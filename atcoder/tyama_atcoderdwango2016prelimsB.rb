#!/usr/bin/ruby
gets;a=gets.split.map &:to_i;puts [a[0],*a.each_cons(2).map(&:min),a[-1]]*' '