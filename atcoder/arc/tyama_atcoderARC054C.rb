#!/usr/bin/ruby
require"matrix"
Fixnum=Integer if !defined?(Fixnum)
class Fixnum;alias/&end
gets;puts [:Even,:Odd][Matrix[*$<.map{|e|e.chop.chars.map &:oct}].det&1]
