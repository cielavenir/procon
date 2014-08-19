#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take57_ajax.php')
Net::HTTP.start(uri.host){|http|
	puts http.post(uri.path,'file=password',{
		'X-Requested-With'=>'XMLHttpRequest',
		'Referer'=>'http://www.hackerschool.jp/hack/take57.php'
	}).body.chomp
}