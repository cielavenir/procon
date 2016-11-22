#!/usr/bin/ruby
n,d,x=gets.split.map &:to_i
r=0
n.times{|i|r+=(n-i)/(i+1.0)}
p r*(d+n*x-x/2.0)
__END__
n,d,x=gets.split.map &:to_f
r=0
n.step(1,-1){|n|r+=d+n*x-x/2;d,x=d+d/n+x/n*5/2,x+x/n*2}
p r
