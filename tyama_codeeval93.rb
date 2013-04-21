#!/usr/bin/ruby
$<.each{|l|puts l.split.map{|e|a=e.split('');a.shift.upcase+a*''}*' '}