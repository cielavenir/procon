#!/usr/bin/ruby
gets;p *$<.map{|e|1<<e.to_i.to_s(2).count(?1)}
