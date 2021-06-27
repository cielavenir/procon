#!/usr/bin/ruby
gets.to_i.times{n,m=gets.split.map &:to_i;m.times{gets};puts n>1 ? :Yes : :No}
