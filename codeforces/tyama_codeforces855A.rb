#!/usr/bin/ruby
h={}
gets.to_i.times{s=gets.chomp;puts h[s]?:YES: :NO;h[s]=1}
