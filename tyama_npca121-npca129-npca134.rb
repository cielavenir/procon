#!/usr/bin/ruby
SESSION='hl4qks7922u5pap1tkelu66bd4'
USER_AGENT='Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/33.0.1750.18 Safari/537.36'

CODE={
	121=>'Happy new  year!',
	129=>'NO',
	134=>'48',
}
question=ARGV[0].to_i
code=CODE[question]

require 'net/https'
http=Net::HTTP.new('judge.npca.jp',443)
http.use_ssl=true
http.start{|http|
	resp=http.post(
		'/submissions/submit/'+question.to_s+'/',
		'_method=POST&data%5BSubmission%5D%5Blanguage_id%5D=10&data%5BSubmission%5D%5Bsource%5D='+code+'%0A',
		{
			'Cookie'=>'CAKEPHP='+SESSION,
			'User-Agent'=>USER_AGENT,
			'Referer'=>'https://judge.npca.jp/submissions/submit/'+question.to_s+'/'
		}
	)
	resp.header.each{|k,v|puts k+': '+v}
	puts resp.body
}