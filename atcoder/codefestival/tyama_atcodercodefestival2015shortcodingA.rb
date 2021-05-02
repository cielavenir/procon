#!/usr/bin/ruby
n,*a=$<.map &:to_i;puts n*2*a[0]>a.reduce(:+)?:Pass: :Fail