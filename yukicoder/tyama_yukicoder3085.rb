#!/usr/bin/ruby
_,_,b=`dd`.split.map &:to_i;p b*-~b/2%17
