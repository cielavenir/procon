#!/usr/bin/ruby
require 'rexml/document'
doc = REXML::Document.new($<.read)
puts doc.elements.each("/collection/movie[contains(description,'bit')]/@title")