#!/usr/bin/ruby
n,m=$<.read.split.map &:to_i
p n<64 ? m%2**n : m
