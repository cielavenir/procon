#!/usr/bin/ruby
require 'net/http'
require 'cgi'
#Stage1
uri1=URI.parse('http://www.hackerschool.jp/hack/'+'11010100001011'.to_i(2).to_s+'.html')
#Stage2
uri=URI.parse('http://www.hackerschool.jp/hack/'+CGI.unescape('%36%33%32').to_i.to_s(16)+'.php')

Net::HTTP.start(uri.host){|http|
	resp=http.get(uri.path,
		{
			'Referer'=>uri1.to_s,
			'Cookie'=>'PHPSESSID=',
		}
	)
	puts resp.body
}