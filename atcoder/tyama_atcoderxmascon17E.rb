#!/usr/bin/ruby
puts`echo #{gets.chomp}|grep -E '^#{gets.gsub(/\n?/,'A*').gsub(/B/,'B?')}$'`[0]?:YES: :NO
