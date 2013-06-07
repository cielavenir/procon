#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take42.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'mode=check',
		{
			'Referer'=>uri.to_s,
			'User-Agent'=>'8946',
			'Cookie'=>'PHPSESSID=',
		}
	)
	puts resp.body
}