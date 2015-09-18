#!/usr/bin/ruby
require 'matrix'
puts Matrix[[1,2,3],[2,3,4],[1,1,1]]*Matrix[[4,5,6],[7,8,9],[4,5,7]]
__END__
30
36
45
45
54
67
15
18
22