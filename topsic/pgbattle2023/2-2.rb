#!/usr/bin/ruby
h={'???'=>27,'A??'=>9,'?B?'=>9,'??C'=>9,'AB?'=>3,'A?C'=>3,'?BC'=>3,'ABC'=>1}
r=0
gets.chomp.chars.each_cons(3){|e|(d=h[e*''])&&r+=1.0/d}
p r
