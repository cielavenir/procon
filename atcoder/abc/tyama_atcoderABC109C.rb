#!/usr/bin/ruby
_,*a=`dd`.split.map &:to_i;p a.sort.each_cons(2).map{|x,y|y-x}.reduce :gcd
