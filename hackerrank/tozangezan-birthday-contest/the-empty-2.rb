#!/usr/bin/ruby
require 'prime'
a,b=`dd`.split.map(&:to_i)
p Prime.each(b).drop_while{|e|e<a}.size