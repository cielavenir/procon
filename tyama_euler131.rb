#!/usr/bin/ruby
require 'prime'
p Prime.each(10**6).select{|e|e%6==1&&Math.sqrt(12*e-3).to_i**2==12*e-3}.count