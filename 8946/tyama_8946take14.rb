#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take14.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'input_id=8946',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'PHPSESSID=',
		}
	)
	puts resp.body
}