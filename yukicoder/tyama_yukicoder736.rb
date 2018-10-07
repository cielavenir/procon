#!/usr/bin/ruby
gets;a=gets.split.map &:to_i;g=a.reduce :gcd;puts a.map{|e|e/g}*':'
