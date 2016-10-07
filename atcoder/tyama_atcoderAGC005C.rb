#!/usr/bin/ruby
e,s=gets;h=gets.split.map(&:to_i).sort.chunk{|e|e}.map{|k,v|s||=k;[e=k,v.size]}.to_h;print h[s]==s*2+1-e&&(s+1..e).all?{|x|h[x].to_i>1}?:P: :Imp,:ossible
