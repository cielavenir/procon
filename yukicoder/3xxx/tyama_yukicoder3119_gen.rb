#!/usr/bin/ruby
require 'zlib'
puts 'h={'
open(File.join(File.dirname(File.realpath(__FILE__)), 'tyama_yukicoder3119.dat')){|f|
while f.gets
f.gets
x=Zlib.crc32(f.gets.chomp)
y=f.gets.chomp
puts '%d=>"%s",' % [x,y]
end
}
puts '}'
