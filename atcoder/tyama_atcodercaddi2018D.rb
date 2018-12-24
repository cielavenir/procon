#!/usr/bin/ruby
gets;puts$<.any?{|e|e.to_i.odd?}?:first: :second
