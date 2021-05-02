#!/usr/bin/ruby
(A,B,C,K),(S,T)=$<.map{|e|e.split.map(&:to_i)}
p A*S+B*T-(S+T<K ? 0 : C)*(S+T)