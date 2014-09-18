#!/usr/bin/ruby
gets
r=-999
s=0
gets.split.each{|e|
s+=e.to_i
r=s if r<s
s=0 if s<0
}
p r