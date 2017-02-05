#!/usr/bin/ruby
_,*a=`dd`.split.map &:to_i;puts [:YES,:NO][a.reduce(:+)%2]
