#!/usr/bin/ruby
F=->n{(n-4..n).reduce(:*)||0}
p 12.0*F[gets.to_i]/F[99]