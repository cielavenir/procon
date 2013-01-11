#!/usr/bin/ruby
a,b,c,d=gets.split.map(&:to_f);p Math.hypot(a-c,b-d)