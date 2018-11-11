#!/usr/bin/ruby
gets;puts$<.sort_by{|e|-Rational(*e.split.map(&:to_i))}
