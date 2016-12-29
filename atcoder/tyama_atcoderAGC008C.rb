#!/usr/bin/ruby
i,o,t,j,l,_=gets.split.map &:to_i;p (0..1).map{|k|i<k||j<k||l<k ?0:(i-k&~1)+(j-k&~1)+(l-k&~1)+3*k+o}.max
