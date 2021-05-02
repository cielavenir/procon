#!/usr/bin/ruby
a,b=gets.split.map{|e|(e.to_i-2)%13};puts %w[Draw Alice Bob][a<=>b]
