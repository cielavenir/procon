#!/usr/bin/ruby
require 'mathn'
$<.each{|l|puts sprintf("%.5f\n",eval(l.gsub('^','**'))).sub(/0+$/,'').sub(/\.$/,'')}