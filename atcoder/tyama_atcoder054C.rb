#!/usr/bin/ruby
require"matrix"
class Fixnum;alias/&end
gets;puts [:Even,:Odd][Matrix[*$<.map{|e|e.chop.chars.map &:oct}].det&1]