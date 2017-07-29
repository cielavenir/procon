#!/usr/bin/ruby
`dd`.split.each_with_index{|e,i|e==?1&&p(i)}
