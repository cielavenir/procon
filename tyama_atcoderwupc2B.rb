#!/usr/bin/ruby
gets;p gets.split('.').map(&:size).reduce{|s,e|s+=e/3}