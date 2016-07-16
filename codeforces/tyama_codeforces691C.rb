#!/usr/bin/ruby
require'bigdecimal';x=BigDecimal(gets).split;s=x[1][0];s<<'.'+x[1][1..-1] if x[1].size>1;s<<'E%d'%[x[3]-1] if x[3]!=1;puts s