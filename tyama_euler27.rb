#!/usr/bin/ruby
require 'prime'
def len(a,b) n=0;while(n*n+a*n+b).prime? do n+=1 end;n end
n=gets.to_i
puts (-n).step(n).map{|a|(-n).step(n).map{|b|[len(a,b),a,b]}.max}.max[1,2]*' '
__END__
999