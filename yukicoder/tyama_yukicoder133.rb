#!/usr/bin/ruby
_,A,b=$<.map{|e|e.split.map(&:to_i)}
i=0.0
p A.permutation.count{|a|i+=1;s=0;a.zip(b){|x,y|s+=x<=>y};s>0}/i