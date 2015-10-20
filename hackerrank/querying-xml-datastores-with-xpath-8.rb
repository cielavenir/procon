#!/usr/bin/ruby
require 'rexml/document'
doc = REXML::Document.new($<.read)
puts doc.elements.each("string-length(/collection/movie[2]/description/text())")