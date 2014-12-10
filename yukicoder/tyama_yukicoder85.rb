#!/usr/bin/ruby
n,m,c=gets.split.map(&:to_i);puts n==1||m==1 ? n*m==2 ? :YES : :NO : n*m%2==1 ? :NO : :YES