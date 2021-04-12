#!/usr/bin/ruby
gets;p *ARGF.each_line.map{|_|n=_.to_i;n<3 ? 2 : (n-1)**2}
