#!/usr/bin/ruby
10.times{h={};10.times{h[gets.to_i%42]=1};p h.size}