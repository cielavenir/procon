#!/usr/bin/ruby
n,k,*a=`dd`.split.map(&:to_i);puts n*k==a.reduce(:+) ? :YES : :NO
