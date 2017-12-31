#!/usr/bin/ruby
require'prime'
A=(1..7**6).select{|e|e.prime?&&(-~e/2).prime?}
gets;$<.map{|_|x,y=_.split.map &:to_i;p A.bsearch_index{|e|e>y}-A.bsearch_index{|e|e>=x}}
