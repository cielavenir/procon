#!/usr/bin/ruby
n,*a=(gets+gets).split.map(&:to_i);z=[];n.times{|i|n.times{|j|if a[i]>a[j];z<<[i,j];a[i],a[j]=a[j],a[i] end}};p z.size;z.each{|e|puts e*' '}