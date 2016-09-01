#!/usr/bin/ruby
require 'net/http'
s=''.dup
Net::HTTP.start('goo.gl'){|http|
	key='xFnLDH'
	location=''
	loop{
		resp=http.get('/'+key)
		h=Hash[*resp]
		break if !h.has_key?('location')
		location=h['location'][0]
		domain,key=location.split('/')[-2..-1]
		s<<domain.scan(/\d/).join
		sleep(1)
	}
	puts location
}
puts s.tr('10','ls')