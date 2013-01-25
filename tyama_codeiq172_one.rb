#!/usr/bin/ruby
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
puts [1,1].instance_eval{enum_for(:each_cons,2).lazy.map{|x,y|push x+y}.take(40).to_a.last}.last(2)*'x'