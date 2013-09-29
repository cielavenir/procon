#!/usr/bin/ruby
require 'prime'
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
p Prime.each.lazy.drop_while{|e|e<=10}.first