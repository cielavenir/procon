#!/usr/bin/ruby
a,b=$<.map &:to_i;$><<[:EQUAL,:GREATER,:LESS][a<=>b]
