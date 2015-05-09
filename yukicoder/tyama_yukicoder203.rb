#!/usr/bin/ruby
p$<.read.split.join.scan(/o*/).map(&:size).max