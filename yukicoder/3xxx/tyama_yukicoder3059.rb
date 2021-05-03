#!/usr/bin/ruby
gets.to_i.times{puts %w(0 45).include?(gets.chomp) ? :Y : :N}
