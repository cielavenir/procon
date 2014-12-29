#!/usr/bin/ruby
require'bigdecimal'
p BigDecimal(2).sqrt(9999).to_s('f').tr('.','').index(gets.chomp)
__END__
find the first
substring equal
to the
given x
from
sqrt(2)