#!/usr/bin/ruby
p (?-+`dd`).split.map(&:to_i).reduce :+
