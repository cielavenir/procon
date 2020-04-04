#!/usr/bin/ruby
x,y,h=gets.split.map &:to_f
x*=1000
y*=1000
a=[x,y].sort
p (0..1/0.0).find{|i|
a.shift while a[0]&&a[0]<=h
!(a[0]&&(a[0]/=2;h*=2))
}
