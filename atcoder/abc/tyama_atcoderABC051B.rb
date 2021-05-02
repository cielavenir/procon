#!/usr/bin/ruby
$/=' ';k,s=$<.map &:to_i;k+=1;p (0...k*k).count{|i|z=s-i%k-i/k;0<=z&&z<k}
