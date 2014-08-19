#!/usr/bin/ruby
#C version is currently confidential
require 'zlib'
$<.binmode
pdf=$<.read[0xf98b,126] #take36.pdf
puts Zlib.inflate(pdf).split.map{|e|(e.to_i(16)^189).chr}*''