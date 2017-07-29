#!/usr/bin/ruby
h=Hash.new 0;gets.chomp.chars{|c|h[c]+=1}
if h.any?{|k,v|k<?a||?m<k}
 puts :Impossible
elsif h.size==13
 puts *?a..?m
elsif h.size==12
 puts (?a..?m).find{|c|h[c]==0}
else
 puts :Impossible
end
