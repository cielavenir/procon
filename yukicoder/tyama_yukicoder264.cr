#!/usr/bin/env crystal
n,k=gets.not_nil!.split.map &.to_i
puts [:Drew,:Lost,:Won][(n-k)%3]