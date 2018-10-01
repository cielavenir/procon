#!/usr/bin/ruby
gets;puts$<.sort_by{|e|e.split.map &:to_i}
