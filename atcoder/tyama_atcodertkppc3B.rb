#!/usr/bin/ruby
n=gets.to_i;[6,11].map{|e|puts n%e<1?:yES: :nO}
