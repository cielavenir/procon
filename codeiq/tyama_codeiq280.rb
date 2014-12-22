#!/usr/bin/ruby
p ('A'..'Z').each_slice(3).to_a.instance_eval{self.shift.zip(*self)}.map(&:join)