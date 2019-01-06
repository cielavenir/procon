#!/usr/bin/ruby
_,n,*a=`dd`.split.map &:to_i
r=[false]*(n+1)
(0..n).each{|i|a.find{|e|e<=i&&!r[i-e]}&&r[i]=true}
puts r[n] ? :First : :Second
