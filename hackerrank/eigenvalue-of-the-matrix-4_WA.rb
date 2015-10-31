#!/usr/bin/ruby
require 'matrix'
v,d,v_inv=Matrix[[2,-1],[-1,2]].inv.eigen
p d
v,d,v_inv=Matrix[[2-4,-1-4],[-1-4,2-4]].eigen
p d
__END__
1/3
1
-7
3