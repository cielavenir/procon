#!/usr/bin/ruby
gets;puts $<.any?{|e|e.index 'LOVE'}?:YES: :NO
