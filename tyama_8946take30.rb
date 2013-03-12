#!/usr/bin/ruby
require 'prime'
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
p Prime.each.lazy.drop(8945).take(1).to_a[0]