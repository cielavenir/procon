#!/usr/bin/ruby
#z=DATA.read.split("\n").map{|e|1-e.split('-').map{|f|f.scan(/a/).size}.reduce(:*)/4.0}
z=[1,1,1,0.75,0.5,0]
p z.zip(gets.split.map(&:to_i)).map{|a,b|a*b}.reduce(:+)*2
__END__
AA-AA
AA-Aa
AA-aa
Aa-Aa
Aa-aa
aa-aa