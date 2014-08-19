#!/usr/bin/ruby
require 'mathn'
puts$<.map{|l|("%.5f"%eval(l.gsub('^','**'))).sub(/0+$/,'').sub(/\.$/,'')}