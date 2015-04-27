#!/usr/bin/ruby
gets.to_i.times{n,k=gets.split.map(&:to_i);puts k>gets.split.count{|e|e.to_i<=0}?:YES: :NO}