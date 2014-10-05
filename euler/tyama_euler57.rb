#!/usr/bin/ruby
N=gets.to_i
q=[1,1];r=[0,1]
result=2.step(N+1).select{|i|q<<2*q[i-1]+q[i-2];r<<2*r[i-1]+r[i-2];q[i].to_s.size>r[i].to_s.size}
#p result.size
puts result.map{|e|e-1}
__END__
1000