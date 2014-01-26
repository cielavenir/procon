#!/usr/bin/ruby
require 'rational'
p 2.step(20).reduce(&:lcm)