#!/usr/bin/ruby
a=[1]
1.step(60){|i|a.push(i%2==1 ? a.last*2 : a.last+1)}
gets.to_i.times{p a[gets.to_i]}