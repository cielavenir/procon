#!/usr/bin/ruby
require 'base64'
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take6/htpasswd.txt')
Net::HTTP.start(uri.host){|http|
	resp=http.get(uri.path)
	a=resp.body.chomp.split(':')
	puts a[0]
	puts Base64.decode64 a[1]
}