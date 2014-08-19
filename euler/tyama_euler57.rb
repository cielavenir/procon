#!/usr/bin/ruby
q=[1,1];r=[0,1]
p 2.step(1001).count{|i|q<<2*q[i-1]+q[i-2];r<<2*r[i-1]+r[i-2];q[i].to_s.size>r[i].to_s.size}