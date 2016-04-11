#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i);b=[a[0],*a.each_cons(2).flat_map{|x,y|x.gcd(y)==1 ? [y] : [1,y]}];p b.size-a.size;puts b*' '