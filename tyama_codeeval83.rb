#!/usr/bin/ruby
while gets
h=Hash.new(0)
$_.upcase.scan(/[A-Z]/).each{|e|h[e]+=1}
s=0
i=26
h.values.sort.reverse.each{|e|s+=i*e;i-=1}
p s
end