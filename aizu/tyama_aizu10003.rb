#!/usr/bin/ruby
h=['<','==','>'];a,b=gets.split.map &:to_i;puts 'a '+h[(a<=>b)+1]+' b'