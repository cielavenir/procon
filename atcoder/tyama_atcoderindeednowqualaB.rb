#!/usr/bin/ruby
gets.to_i.times{puts gets.chomp.bytes.sort=='indeednow'.bytes.sort ? :YES : :NO}
#gets;puts$<.map{|e|e.chomp.chars.sort*''=='ddeeinnow'?:YES: :NO}