#!/usr/bin/ruby
puts gets.split.max{|a,b|
c=a.size<=>b.size
(0...a.size).each{|i|c=a[i]==?4&&b[i]==?7 ? 1 : a[i]==?7&&b[i]==?4 ? -1 : a[i]<=>b[i];break if c!=0} if c==0
c
}