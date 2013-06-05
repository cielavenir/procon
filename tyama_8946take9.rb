#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take9.php')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'input_no=1&answer_val=45',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'PHPSESSID=bcffklhro87elkfgncbufgqvm1',
		}
	)
	puts resp.body
}