#!/usr/bin/ruby
z=->(n){(-1)**(n/2)*$_.to_f**n/(2..n).reduce(1,:*)}
gets;while gets
8.step(s=c=0,-2){|i|s+=z[i+1];c+=z[i]};p s,c
end