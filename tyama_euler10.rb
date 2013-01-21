#!/usr/bin/ruby
require 'prime'
p Prime.each(2000000).reduce(:+)