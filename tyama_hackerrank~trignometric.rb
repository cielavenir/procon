#!/usr/bin/ruby
z=->(n){(-1)**(n/2)*$x**n/((1..n).reduce(:*)||1)}
gets;$<.map{|e|$x=e.to_f;s=c=0;5.times{|i|s+=z[2*i+1];c+=z[2*i]};p s,c}