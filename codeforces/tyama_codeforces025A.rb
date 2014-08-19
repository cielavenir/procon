#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i);puts a.index(a.partition(&:odd?).min_by(&:size)[0])+1