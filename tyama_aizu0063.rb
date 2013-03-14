#!/usr/bin/ruby
p$<.count{|e|e.chomp!;e==e.reverse}