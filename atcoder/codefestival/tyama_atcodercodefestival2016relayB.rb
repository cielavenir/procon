#!/usr/bin/ruby
s=gets.chomp;puts s==s.reverse.tr('bdpq','dbqp') ? :Yes : :No
