#!/usr/bin/ruby
require 'prime'
p [*1..7].permutation.map{|a|a.join.to_i}.select(&:prime?).max