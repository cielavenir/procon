#!/usr/bin/ruby
p gets.split('').zip(gets.split('')).count{|a,b|a!=b}