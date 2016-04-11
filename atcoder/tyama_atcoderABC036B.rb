#!/usr/bin/ruby
gets;puts$<.map{|e|e.chomp.chars}.reverse.transpose.map &:join