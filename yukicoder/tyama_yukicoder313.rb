#!/usr/bin/ruby
h=Hash.new(0);gets.chomp.chars{|c|h[c]+=1}
puts (0..9).minmax_by{|i|[20104,20063,19892,20011,19874,20199,19898,20163,19956,19841][i]-h[i.to_s]}*' '