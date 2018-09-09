#!/usr/bin/ruby
gets;s=gets.chomp;p s.tr('?','').squeeze.include?('KD') ? 0 : (s.index('K')||s.size)-(s.rindex('D')||-1)
