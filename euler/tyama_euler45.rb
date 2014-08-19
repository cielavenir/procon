#!/usr/bin/ruby
require 'enumerable/lazy' if RUBY_VERSION<'2.0'
t=[];p={};h={}
1.step(99999).each{|i|t<<i*(i+1)/2;p[i*(3*i-1)/2]=1;h[i*(2*i-1)]=1}
p t.lazy.select{|e|p[e]&&h[e]}.drop(2).first