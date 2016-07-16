#!/usr/bin/ruby
n,*a=(gets+gets).split.map(&:to_i);z=[];n.times{|i|k=(i...n).max_by{|j|a[j]};if i<k;z<<[i,k];a[i],a[k]=a[k],a[i] end};p z.size;z.each{|e|puts e*' '}