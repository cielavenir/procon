#!/usr/bin/ruby
require 'rexml/document'
doc = REXML::Document.new($<.read)
puts doc.elements.each("/collection/movie[popularity/text()<8]/format/text()")