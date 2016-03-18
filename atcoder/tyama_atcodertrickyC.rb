#!/usr/bin/ruby
gets;$<.map{|e|q,x=e.split.map &:to_i;q==2?p(q**x-1):(0..1/0.0).find{|i|y=n=i;y-=n/=q while n>0;x>y&&next;p x<y ?-1:i}}