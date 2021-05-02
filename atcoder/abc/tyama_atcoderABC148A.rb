#!/usr/bin/ruby
a=`dd`.split.map &:to_i;p *[1,2,3]-a
