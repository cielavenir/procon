#!/usr/bin/ruby
gets;p gets.split('.').map(&:length).reduce{|s,e|s+=e/3}