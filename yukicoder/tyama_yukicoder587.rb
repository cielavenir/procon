#!/usr/bin/ruby
h=Hash.new 0;gets.chomp.chars{|c|h[c]+=1}
if h.size>7||h.any?{|k,v|v>2}
 puts :Impossible
else
 puts h.find{|k,v|v==1}[0]
end
