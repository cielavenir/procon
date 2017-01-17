#!/usr/bin/ruby
n=gets.to_i;p n>2?n-2:n+2
__END__
require'prime';n=gets.to_i;p (1..1/0.0).find{|i|!(n*i+1).prime?}
