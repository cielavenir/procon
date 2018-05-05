#!/usr/bin/ruby
require'prime';p *Prime.each(1499).select{|e|e%5>3}[0,gets.to_i]
