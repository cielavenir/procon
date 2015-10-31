#!/usr/bin/ruby
require 'matrix'
v,d,v_inv=Matrix[[2,-1],[-1,2]].eigen
p d
v,d,v_inv=(Matrix[[2,-1],[-1,2]]**2).eigen
p d
__END__
1
3
1
9