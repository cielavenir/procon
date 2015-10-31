#!/usr/bin/ruby
require 'matrix'
v,d,v_inv=Matrix[[1,-3,3],[3,-5,3],[6,-6,4]].eigen
p d
__END__
-2
4