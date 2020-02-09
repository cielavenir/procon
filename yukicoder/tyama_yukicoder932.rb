#!/usr/bin/ruby
puts gets.chomp.split(',').all?{|e|e=='AC'} ? 'Done!' : 'Failed...'
