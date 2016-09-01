#!/usr/bin/ruby
puts gets.chomp.tr('A-Z','KSYWQJDRZUIPGOLMXEBTVAFNHC').each_byte{|b|((b-65+4)%26+65).chr}*''