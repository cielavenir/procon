#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take35_mobile/')
Net::HTTP.start(uri.host){|http|
	resp=http.post(
		uri.path,
		'mode=chk',
		{
			'User-Agent'=>'DoCoMo/2.0 F900i(c100;TB;W22H12;ser365079045783623;iccxxxxxxxxxxxxxxxxxxxx)',
		}
	)
	puts resp.body
}