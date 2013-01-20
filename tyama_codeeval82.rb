#!/usr/bin/ruby
while gets
s=$_.chomp
puts s.chars.reduce(0){|x,e|x+=e.to_i**s.size}==s.to_i ? :True: :False
end