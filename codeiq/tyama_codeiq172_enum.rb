#!/usr/bin/ruby
puts Enumerator.new{|y|a,b=1,2;loop{y<<(a,b=b,a+b)}}.take(40).last*'x'