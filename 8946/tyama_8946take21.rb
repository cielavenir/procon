#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take21.php')
Net::HTTP.start(uri.host){|http|
	resp=http.get(uri.path)
	resp.header.each{|k,v|puts k+': '+v}
}