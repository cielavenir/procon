#!/usr/bin/ruby
#coding:utf-8

#https://www.dropbox.com/s/mj92ccgvwoit746/oauth2.cgi を用いて取得
ACCESS_TOKEN=''

require 'net/https'
require 'json'
require 'prime'
https=Net::HTTP.new('api.github.com',443)
https.use_ssl=true
https.start{
	p DATA.count{|e|
		resp=https.get('/users/'+e.chomp,{'Authorization'=>'token '+ACCESS_TOKEN})
		redo if resp.code.to_i!=200
		#p JSON.parse(resp.body)['id']
		JSON.parse(resp.body)['id'].prime?
	}
	resp=https.get('/user',{'Authorization'=>'token '+ACCESS_TOKEN})
	p JSON.parse(resp.body)
}

__END__
naoya
dhh
mitchellh
KentBeck
martinfowler
matz
twada
gvanrossum
pragdave
jeresig