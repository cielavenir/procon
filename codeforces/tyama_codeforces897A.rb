#!/usr/bin/ruby
gets
s=gets.chomp
$<.each{|_|
a,b,c,d=_.split
(a.to_i-1...b.to_i).each{|i|s[i]=d if s[i]==c}
}
puts s
