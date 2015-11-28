#!/usr/bin/ruby
1000.times{|i|puts '%03d'%i;STDOUT.flush;exit if gets.chomp=='unlocked'}