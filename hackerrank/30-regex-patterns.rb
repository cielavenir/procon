#!/usr/bin/ruby
gets;puts$<.map(&:split).select{|x,y|y.end_with?('@gmail.com')}.map(&:first).sort