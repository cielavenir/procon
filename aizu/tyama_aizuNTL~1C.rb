#!/usr/bin/ruby
require'rational'
gets;p gets.split.map(&:to_i).reduce(&:lcm)