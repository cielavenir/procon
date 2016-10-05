#!/usr/bin/ruby
require'bigdecimal';puts (BigDecimal('0.'+[*1..100]*'')*gets.to_i).to_s(?f)
