#!/usr/bin/ruby
a=!gets
i=0
$<.map(&:split).transpose.map{|e|i+=1;a=a ?-1:i if~e.count('nyanpass')==-e.size}
p a||-1