#!/usr/bin/ruby
x,y=$<.map &:to_f;p 2*Math::PI*(y-x)
