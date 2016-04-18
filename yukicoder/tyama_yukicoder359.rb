#!/usr/bin/ruby
f=->a,b,c{a<c&&((b<a&&b<c)||(b>a&&b>c))}
$><<gets.split.map(&:to_i).permutation.any?{|e|e.each_cons(3).all?(&f)}?:YES: :NO