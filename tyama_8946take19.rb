#!/usr/bin/ruby
require 'net/http'
Net::HTTP.start('www.hackerschool.jp'){|http|
	resp=http.post(
		'/hack/take19.php?id=1&id2=99',
		'input_id=abcd&ymd='+Time.now.strftime('%Y/%m/%d')+'&pass='+'whitehackerz'.bytes.map{|e|((e-83)%26+0x60).chr}*'',
		{
			'Referer'=>uri.to_s,
			'Cookie'=>'PHPSESSID=bcffklhro87elkfgncbufgqvm1;',
		}
	)
	puts resp.body
}