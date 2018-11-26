#!/usr/bin/ruby
n,m,*r=`dd`.split.map &:to_i
a=n*Math.log10(m)
r.map{|k|a+=(1..k).map{|e|Math.log10 e}.reduce 0,:+}
p (a-((1..n).map{|e|Math.log10 e}.reduce :+)).ceil
__END__
a=m**n
r.map{|k|a*=(1..k).reduce :*}
p Math.log10(a/(1..n).reduce(:*).to_f).ceil
