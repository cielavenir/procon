#!/usr/bin/ruby
#C version is currently confidential
require 'zlib'
pdf=''
File.open(ARGV[0],'rb'){|f|pdf=f.read[0xf98b,126]} #take36.pdf
puts Zlib.inflate(pdf).split.map{|e|(e.to_i(16)^189).chr}*''