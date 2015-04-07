#!/usr/bin/ruby
#http://kcs.miz-miz.biz/contest/1031/code/100137
p gets[3,4].bytes.zip([*4..7]).reduce(3){|s,(x,y)|s+x*y}%11%10