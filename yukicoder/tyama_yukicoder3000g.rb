#!/usr/bin/ruby
require'bigdecimal'
p BigDecimal(2).sqrt(9999).to_s('f').tr('.','').index(gets.chomp)