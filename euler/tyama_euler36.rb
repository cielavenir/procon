#!/usr/bin/ruby
n,k=gets.split.map(&:to_i)
p n.times.map{|i|s,t=i.to_s,i.to_s(k);s.reverse==s&&t.reverse==t ?i:0}.reduce(:+)
__END__
1000000 2