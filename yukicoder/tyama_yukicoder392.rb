#!/usr/bin/ruby
gets;puts$<.map{|e|(e.to_i+1).to_s(2)[1..-1].tr'01','LR'}