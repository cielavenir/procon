#!/usr/bin/ruby
require 'time';begin loop{puts (Time.parse(gets)+gets.to_i(2)).strftime("%Y/%m/%d %H:%M:%S")};rescue;end