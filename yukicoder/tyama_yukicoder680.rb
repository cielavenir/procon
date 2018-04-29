#!/usr/bin/ruby
F=->t{t*2-t.to_s(2).count(?1)}
N=gets.to_i
puts F[(0..2*N).bsearch{|t|F[t]>=N}]==N ? :YES: :NO
