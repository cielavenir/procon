#!/usr/bin/ruby
gets;gets
mi,ma=$<.map(&:to_i).minmax
p ma-mi