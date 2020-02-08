#!/usr/bin/env crystal
n=gets.not_nil!.to_i64*108
puts "%d.%02d" % [n//100,n%100]
