#!/usr/bin/ruby
#Note: due to 302 status code, Mechanize is not applicable.
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take15_answer.php')
Net::HTTP.start(uri.host){|http|
	resp=http.get(uri.path)
	puts resp.body
}