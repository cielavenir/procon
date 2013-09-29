#!/usr/bin/ruby
require 'prime'
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
p Prime.each.lazy.take_while{|e|e<2000000}.reduce(:+)