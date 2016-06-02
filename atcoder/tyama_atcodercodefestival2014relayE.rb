#!/usr/bin/ruby
#gets;p$<.read.chars.map(&:to_i).reduce(:+)
p`sed 1d`.chars.map(&:hex).reduce:+