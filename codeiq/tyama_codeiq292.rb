#!/usr/bin/ruby
require 'prime'
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
Prime.each.lazy.take(100).each{|e|p e}