#!/usr/bin/ruby
A,N,*F=$<.map(&:chomp);puts A.split.map{|a|F.any?{|f|a=~/^#{f.gsub('*','.')}$/}?'*'*a.size: a}*' '