#!/usr/bin/ruby
require 'prime';
h={};a=[]
Prime.each(gets.to_i-1){|e|h[e]=1;a<<e.to_s}
p a.select{|s|s.size.times.map{|i|h[(s[i,s.size-i]+s[0,i]).to_i]}.all?}.map(&:to_i).reduce(:+)
#{}.size for euler
__END__
1000000