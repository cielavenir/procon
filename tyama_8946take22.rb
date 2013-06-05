#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take22.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'pass=take22password',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'PHPSESSID=',
		}
	)
	puts resp.body
}