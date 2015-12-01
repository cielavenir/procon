#!/usr/bin/ruby
gets.to_i.times{
gets.chomp.bytes{|b|$><<(((b-65-3)%26)+65).chr<<(((b-65+4)%26)+65).chr}
puts
}