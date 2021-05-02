#!/usr/bin/ruby
l=gets.to_i;r=2*l+l*=l;while r/100>=z=(l+99)/100;l,r=z,r/100 end;p l