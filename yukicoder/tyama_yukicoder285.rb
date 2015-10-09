#!/usr/bin/ruby
require 'bigdecimal'
puts (BigDecimal(gets)*BigDecimal('1.08')).to_s('f')