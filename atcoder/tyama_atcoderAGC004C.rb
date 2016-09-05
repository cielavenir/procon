#!/usr/bin/ruby
h,w=gets.split.map &:to_i
m=$<.map{|e|e.chomp[1..-2]}
2.times{|i|h.times{|y|s=['#'*(w-2),m[y]][y%2^i];puts ["##{s}.",".#{s}#"][i]};puts}