#!/usr/bin/ruby
puts (Time.new(*gets.split(?/).map(&:to_i))+2e5).strftime'%Y/%02m/%02d'
