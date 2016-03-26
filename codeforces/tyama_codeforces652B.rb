#!/usr/bin/ruby
gets;a=gets.split.map(&:to_i).sort;b=a.pop(a.size/2).reverse;puts a.zip(b)*' '