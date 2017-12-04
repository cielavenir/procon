#!/usr/bin/ruby
z=360
n,*a=$<.read.split.map &:to_i
(-n..-1).each{|i|
r=0
(i...i+n).each{|j|r+=a[j];z=[z,(360-2*r).abs].min}
}
p z
