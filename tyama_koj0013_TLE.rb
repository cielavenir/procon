#!/usr/bin/ruby
while(a,b=gets.chomp.split)!=['-1','-1']
a=a[[-2,-a.size].max..-1].to_i
b=b[[-2,-b.size].max..-1].to_i+100
puts [*a..b].count(&:odd?).odd? ? :ODD : :EVEN

#puts ((b-1)/2-(a-2)/2).odd? ? :ODD : :EVEN
#puts ((((b+1)>>1)-(a>>1))&1)==1 ? :ODD : :EVEN
end