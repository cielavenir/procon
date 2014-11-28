#!/usr/bin/ruby -rprime
puts gets.to_i.prime_division.reduce(0){|s,(n,p)|s^p}>0 ? :Alice : :Bob