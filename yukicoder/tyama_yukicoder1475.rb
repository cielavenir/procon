#!/usr/bin/ruby
gets;$<.each{|e|puts e.split[1..-1].map(&:to_i).sort.reverse*' '}
