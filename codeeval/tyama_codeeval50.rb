#!/usr/bin/ruby
while gets
s,t=$_.chomp.split(';')
a=t.split(',').each_slice(2).to_a.transpose
a[0].each_with_index{|e,i|s.gsub!(e,(i+65).chr)}
a[1].each_with_index{|e,i|s.gsub!((i+65).chr,e)}
puts s
end