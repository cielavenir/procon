#!/usr/bin/ruby
require 'rexml/document'
doc = REXML::Document.new($<.read)
puts REXML::XPath.match(doc,"sum(/collection/movie/popularity/text()) div count(/collection/movie/popularity/text())")