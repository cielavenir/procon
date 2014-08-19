#!/usr/bin/ruby
puts gets.chomp.tr(' ?','')[-1..-1].scan(/[AEIOUYaeiouy]/).size>0 ? 'YES' : 'NO'