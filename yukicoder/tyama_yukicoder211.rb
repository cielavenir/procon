#!/usr/bin/ruby
h=Hash.new(0)
[2,3,5,7,11,13].product([4,6,8,9,10,12]){|x,y|h[x*y]+=1}
p h[gets.to_i]/36.0