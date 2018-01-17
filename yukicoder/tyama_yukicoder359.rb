#!/usr/bin/ruby
#Ruby 2.2.0 - 2.4.0: lambda was OK (2.4.1 accepts only proc)
#f=->a,b,c{a<c&&((b<a&&b<c)||(b>a&&b>c))}
f=proc{|a,b,c|a<c&&((b<a&&b<c)||(b>a&&b>c))}
$><<gets.split.map(&:to_i).permutation.any?{|e|e.each_cons(3).all?(&f)}?:YES: :NO
