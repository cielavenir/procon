#!/usr/bin/ruby
a,b=gets.split.map &:to_i;a+=1-b;puts a>0?[:NO,a]:[:YES,-a]
