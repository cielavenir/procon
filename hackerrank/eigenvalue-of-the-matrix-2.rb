#!/usr/bin/ruby
require 'matrix'
v,d,v_inv=Matrix[[1,2],[2,4]].eigen
p d
__END__
0
5