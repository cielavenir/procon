#!/usr/bin/ruby
gets.to_i.times{gets;p (1..6).map{Complex(*gets.split.map(&:to_f)).angle*57.29578}.find{|e|-1<e&&e<51}}