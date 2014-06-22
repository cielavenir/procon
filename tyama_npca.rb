#!/usr/bin/ruby
require 'cgi'
SESSION=''
USER_AGENT='Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/36.0.1985.67 Safari/537.36'

CODE={
	53=>"#!",
	117=>"Canis lupus\nCMS\nFranz Liszt\nUtah\n",
	120=>"20,134\n22,827,361\n446\n51,453,221,984,557,556\n",
	121=>"Happy new  year!\n",
	129=>"NO\n",
	134=>"48\n",
	149=>"666848483\n",
	156=>"1\n",
	160=>"Hard\n",
	193=>"A+B\n",
}
question=ARGV[0].to_i
code=CGI.escape(CODE[question])

require 'net/https'
http=Net::HTTP.new('judge.npca.jp',443)
http.use_ssl=true
http.start{|http|
	resp=http.post(
		'/submissions/submit/'+question.to_s+'/',
		'_method=POST&data%5BSubmission%5D%5Blanguage_id%5D=10&data%5BSubmission%5D%5Bsource%5D='+code,
		{
			'Cookie'=>'CAKEPHP='+SESSION,
			'User-Agent'=>USER_AGENT,
			'Referer'=>'https://judge.npca.jp/submissions/submit/'+question.to_s+'/'
		}
	)
	resp.header.each{|k,v|puts k+': '+v}
	puts resp.body
}