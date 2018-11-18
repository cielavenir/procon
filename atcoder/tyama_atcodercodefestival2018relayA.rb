#!/usr/bin/ruby
A=%w(Mon Tue Wed Thu Fri Sat Sun);gets;puts$<.map{|e|A[A.index(e.chomp)-6]}
