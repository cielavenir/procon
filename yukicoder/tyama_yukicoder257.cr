#!/usr/bin/env crystal
n,k=gets.not_nil!.split.map &.to_i
9.times{|i|puts (~-n%-~k)-(~k*i)}