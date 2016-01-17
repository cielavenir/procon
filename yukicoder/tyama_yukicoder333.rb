#!/usr/bin/ruby
a,b=gets.split.map &:to_i; p a<b ?b-2:2000000000+~b