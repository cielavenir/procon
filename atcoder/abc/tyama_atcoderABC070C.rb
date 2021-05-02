#!/usr/bin/ruby
gets;p $<.map(&:to_i).reduce :lcm
