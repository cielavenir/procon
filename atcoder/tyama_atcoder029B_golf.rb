#!/usr/bin/ruby
(H,W),_,*A=$<.map{|e|e.split.map(&:to_f).sort}
X=Math.hypot H,W
gets;puts A.map{|y,x|y<H ? :NO:W<=x||X*Math.sin(Math.asin(y/X)-Math.asin(H/X)+Math.asin(W/X))<x ?:YES: :NO}
