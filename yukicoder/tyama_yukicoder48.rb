#!/usr/bin/ruby
x,y,l=$<.map(&:to_i);p (x.abs+l-1)/l+(y.abs+l-1)/l+(y<0 ? 2 : x==0 ? 0 : 1)